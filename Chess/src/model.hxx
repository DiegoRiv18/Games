#pragma once

#include <ge211.hxx>
#include "position_set.hxx"

class Model
{
public:
    Model();

    using Position = ge211::Posn<int>;

    const int grid_size = 8;

    // getter function for square
    std::string piece_at(int i, int j) const;

    void piece_set(int i, int j, std::string piece);

    std::string get_turn() const;

    void change_turn();

    void check_promote();

    bool check_cm_black();

    bool check_cm_white();

    Position_set find_moves(std::string piece, Position pos) const;

    void set_selected (std::string piece);
    std::string get_selected () const;

    void set_pos (Position pos);
    Position get_pos() const;

    void set_piece_pos(Position pos);
    Position get_piece_pos() const;

    Position_set find_all_moves_white();

    Position_set find_all_moves_black();

private:
    std::string turn_ = "W";

    std::string board_[8][8];

    std::string selected = " ";

    Position current_pos = {0,0};

    Position piece_pos = {-1,-1};

    Position_set moves = {};

    Position_set bp_valid_moves(Position pos)const;
    Position_set wp_valid_moves(Position pos)const;
    Position_set br_valid_moves(Position pos)const;
    Position_set wr_valid_moves(Position pos)const;
    Position_set bn_valid_moves(Position pos)const;
    Position_set wn_valid_moves(Position pos)const;
    Position_set bb_valid_moves(Position pos)const;
    Position_set wb_valid_moves(Position pos)const;
    Position_set wq_valid_moves(Position pos)const;
    Position_set bq_valid_moves(Position pos)const;
    Position_set bk_valid_moves(Position pos)const;
    Position_set wk_valid_moves(Position pos) const;

};
