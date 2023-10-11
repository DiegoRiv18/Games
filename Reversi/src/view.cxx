#include "view.hxx"

// Convenient type aliases:

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const circle_radius = 15;
static int const tile_padding = 2;
static int const tile_side = 2 * (circle_radius + tile_padding);
static int const tile_margin = 1;
static int const grid_size = tile_side + 2 * tile_margin;
static Color const tile_color = Color::medium_green();
static Color const flip_color = Color::medium_red();
static Color const light_color = Color::white();
static Color const dark_color = Color::black();
static Color const grey_color = light_color.blend(0.5, dark_color);


// You can change this or even determine it some other way:

static Position_set const empty_position_set;

Position_set const&
View::current_flips_(Position mouse_pos) const
{
    Move const *movep = model_.find_move(mouse_pos);
    if (movep) {
        return movep->second;
    } else {
        return empty_position_set;
    }
}

View::View(Model const& model)
        : model_(model),
        tile_sprite_ {{tile_side, tile_side}, tile_color},
        flip_sprite_ {{tile_side, tile_side}, flip_color},
        light_sprite_ {circle_radius, light_color},
        dark_sprite_ {circle_radius, dark_color},
        grey_sprite_ {circle_radius, grey_color},
        small_light_sprite_{circle_radius/2, dark_color},
        small_dark_sprite_{circle_radius/2, light_color}
        // You may want to add sprite initialization here
{ }

void View::draw(Sprite_set& set, Position mouse_pos)
{
    // TODO, PROBABLY
    //Set up board

    Position_set const& flips = current_flips_(screen_to_board(mouse_pos));

    for (Position board_pos : model_.board()) {
        Position screen_pos = board_to_screen(board_pos);

        Position tile_pos =
                screen_pos + Dimensions {tile_margin, tile_margin};

        Position token_pos =
                tile_pos + Dimensions {tile_padding, tile_padding};

        if (flips[board_pos]) {
            set.add_sprite(flip_sprite_, tile_pos, 0);
            if(model_.turn() == Player::light) {
                set.add_sprite(small_dark_sprite_, (mouse_pos), 1);
            }
            else {
                set.add_sprite(small_light_sprite_, (mouse_pos),1);
            }
        }
        else {
            set.add_sprite(tile_sprite_, tile_pos, 0);
        }

        add_player_sprite_(set, model_[board_pos], token_pos, 1);
    }

    //add_player_sprite_(set, model_.turn(), mouse_pos, 2);
}


View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return grid_size * model_.board().dimensions();
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Reversi";
}

View::Position
View::board_to_screen(Model::Position pos) const
{
    return {grid_size * pos.x, grid_size * pos.y};
}

Model::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / grid_size, pos.y / grid_size};
}

void
View::add_player_sprite_(
        Sprite_set& set,
        Player player,
        Position pos,
        int z) const
{
    // TODO
    if (player == Player::neither) { return; }

    if (model_.is_game_over() && player != model_.winner()) {
        set.add_sprite(grey_sprite_, pos, z);
    } else if (player == Player::light) {
        set.add_sprite(light_sprite_, pos, z);
    } else {
        set.add_sprite(dark_sprite_, pos, z);
    }

}