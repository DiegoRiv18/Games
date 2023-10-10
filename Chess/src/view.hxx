#pragma once

#include "model.hxx"

static const int cell_size = 100;

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    explicit View(Model const& model,
                  ge211::Mixer& mixer);

    Dimensions initial_window_dimensions() const;

    void draw(ge211::Sprite_set& set, Position mouse_pos);

    Position screen_to_board(Position screen_pos) const;

    Position board_to_screen(Position board_pos) const;

    void play_sound_effect() const;


private:
    Model const& model_;

    ge211::Font sans30_{"sans.ttf", 30};
    ge211::Text_sprite letter_sprite_[8][8];
    ge211::Rectangle_sprite const tile_sprite_, possible_sprite_,select_sprite_;
    ge211::Circle_sprite const small_white_sprite_, small_black_sprite_;

    void load_audio_();

    Position_set valid_moves = {};
    Position mouse_pos_ = {4,4};

    ge211::Mixer& mixer_;
    ge211::Sound_effect place_sound;
};
