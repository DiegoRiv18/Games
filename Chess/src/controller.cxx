#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : view_(model_,mixer()),
          old_pos(-1, -1)
{

}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, mouse_position_);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q')) {
        quit();
    }
    if (key == ge211::Key::code('s')){
        if(model_.get_turn() == "W"){
            std::cout << "WHITE SURRENDERS, BLACK WINS!";
            quit();
        }
        else{
            std::cout << "BLACK SURRENDERS, WHITE WINS!";
            quit();
        }
    }
}
void
Controller::on_mouse_move(ge211::Posn<int> mouse_pos)
{
    mouse_position_ = mouse_pos;
}
void
Controller::on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
{
    View::Position board_pos = view_.screen_to_board(position);
    model_.set_pos(board_pos);

    if(m == ge211::Mouse_button::left){
        if(selected == " ") {
            if(model_.get_turn() == "W"
               && model_.piece_at(board_pos.y, board_pos.x)[0] == *"W"){
                model_.set_piece_pos(board_pos);
                old_pos = view_.screen_to_board(position);
                selected = model_.piece_at(board_pos.y, board_pos.x);
                moves |= model_.find_moves(selected,board_pos);
                if(moves.empty()) {
                    selected = " ";
                }
                model_.set_selected(selected);
                model_.set_pos(board_pos);
                for(ge211::Posn<int> possible_move: moves) {
                    std::cerr << selected << "Possible moves: " << possible_move
                    << "\n";
                }
            }
            if(model_.get_turn() == "B"
               && model_.piece_at(board_pos.y, board_pos.x)[0] == *"B"){
                model_.set_piece_pos(board_pos);
                old_pos = view_.screen_to_board(position);
                selected = model_.piece_at(board_pos.y, board_pos.x);
                moves |= model_.find_moves(selected,board_pos);
                if(moves.empty()) {
                    selected = " ";
                }
                model_.set_selected(selected);
                model_.set_pos(board_pos);
                for(ge211::Posn<int> possible_move: moves) {
                        std::cerr << selected << " " << "Possible moves: " <<
                              possible_move <<
                              "\n";
                }
            }
        }
        else {
                if (board_pos != old_pos){
                    if(moves[board_pos]) {
                        view_.play_sound_effect();
                        model_.piece_set(board_pos.x, board_pos.y, selected);
                        selected = " ";
                        model_.piece_set(old_pos.x, old_pos.y, " ");
                        model_.set_selected(" ");
                        model_.set_piece_pos({-1,-1});
                        moves.clear();
                        model_.check_promote();
                        model_.change_turn();
                    }
                }

            else {
                if (board_pos != old_pos){
                    if(moves[board_pos]) {
                        view_.play_sound_effect();
                        model_.piece_set(board_pos.x, board_pos.y, selected);
                        selected = " ";
                        model_.piece_set(old_pos.x, old_pos.y, " ");
                        model_.set_selected(" ");
                        model_.set_piece_pos({-1,-1});
                        moves.clear();
                        model_.check_promote();
                        model_.change_turn();
                    }
                }
            }
        }
    }

    if(m == ge211::Mouse_button::right){
        selected = " ";
        model_.set_piece_pos({-1,-1});
        model_.set_selected(" ");
    }
}