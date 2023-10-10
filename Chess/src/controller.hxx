#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;

    View::Dimensions initial_window_dimensions() const override;

    void on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
    override;

    void on_mouse_move(View::Position) override;

    void on_key(ge211::events::Key key)override;


private:
    Model model_;
    View view_;
    std::string selected = " ";
    View::Position old_pos;
    View::Position mouse_position_{-1,-1};
    Position_set moves = {};
    bool white_cm = false;
    bool black_cm = false;
};
