#include "view.hxx"
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static std::string const sound_effect_filename {"place_sound.ogg"};

static int const tile_padding = 26;
static int const tile_side = cell_size - 2;
static Color const tile_color = Color::medium_green();
static Color const possible_color = Color::medium_red();
static Color const select_color = Color::medium_yellow();
static Color const white_color = Color::white();
static Color const black_color = Color::black();


View::View(Model const& model,
           ge211::Mixer& mixer)
        : model_(model),
          tile_sprite_ {{tile_side, tile_side}, tile_color},
          possible_sprite_ {{tile_side, tile_side}, possible_color},
          select_sprite_{{tile_side,tile_side}, select_color},
          small_white_sprite_{8, white_color},
          small_black_sprite_{8, black_color},
          mixer_(mixer)
{
    if (mixer_.is_enabled()) {
        load_audio_();
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return {cell_size * model_.grid_size, cell_size * model_.grid_size};
}

void
View::draw(ge211::Sprite_set& set, Position mouse_pos)
{
    Position_set possible_moves = model_.find_moves(model_.get_selected(),model_
    .get_pos());

    for (int i = 0; i < model_.grid_size; i++) {
        for (int j = 0; j < model_.grid_size; j++) {


            ge211::Text_sprite::Builder letter_builder(sans30_);
            letter_builder << model_.piece_at(j, i);

            letter_sprite_[j][i].reconfigure(letter_builder);

            set.add_sprite(letter_sprite_[j][i], {i*cell_size + tile_padding,
                                                  j*cell_size +
                                                  tile_padding}, 2);
            set.add_sprite(tile_sprite_, {i*cell_size,j*cell_size}, 0);

            set.add_sprite(select_sprite_,
                           {model_.get_piece_pos().x*cell_size,
                            model_.get_piece_pos().y*cell_size},
                            1);

            if(possible_moves[{i,j}]){
                set.add_sprite(possible_sprite_,{i * cell_size,j *cell_size},1);
            }
            if(model_.get_turn() == "W") {
                set.add_sprite(small_white_sprite_, (mouse_pos), 3);
            }
            else {
                set.add_sprite(small_black_sprite_, (mouse_pos),3);
            }
        }
    }

}

View::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / cell_size, pos.y / cell_size};
}

View::Position
View::board_to_screen(Model::Position pos) const
{
    return {model_.grid_size * pos.x, model_.grid_size * pos.y};
}

void
View::play_sound_effect() const
{
    mixer_.try_play_effect(place_sound);
}

void
View::load_audio_()
{
    place_sound.try_load(sound_effect_filename,mixer_);
}

