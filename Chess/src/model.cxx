#include "model.hxx"
#include "position_set.hxx"
#include <iostream>

Model::Model()
    : board_ {{"BR","BN","BB","BQ","BK","BB","BN","BR"},
                {"BP","BP","BP","BP","BP","BP","BP","BP"},
                {" ", " ", " ", " ", " ", " ", " ", " "},
                {" ", " ", " ", " ", " ", " ", " ", " "},
                {" ", " ", " ", " ", " ", " ", " ", " "},
                {" ", " ", " ", " ", " ", " ", " ", " "},
                {"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
                {"WR","WN","WB","WQ","WK","WB","WN","WR"}}

{

}

std::string Model::piece_at(int i, int j) const {
    return board_[i][j];
}

void Model::piece_set(int i, int j, std::string piece) {
    board_[j][i] = piece;
}

void Model::change_turn()
{
    if (turn_ == "W") {
        turn_ = "B";
    }
    else {
        turn_ = "W";
    }
}

std::string Model::get_turn() const
{
    return turn_;
}

void Model::check_promote()
{
    for(int i = 0; i < grid_size; i++){
        if(piece_at(0, i) == "WP") {
            board_[0][i] = "WQ";
        }
    }
    for(int i = 0; i < grid_size; i++){
        if(piece_at(7,i) == "BP") {
            board_[7][i] = "BQ";
        }
    }
}

bool
Model::check_cm_black()
{ //Check if black is in checkmate
    Position_set current_moves = find_all_moves_white();
    std::cerr << "ALL WHITE MOVES: " << current_moves << "\n";
    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++) {
            if(piece_at(j,i) == "BK"){
                if(current_moves[{i,j}]){
                    return true;
                }
            }
        }
    }

    return false;
}

bool
Model::check_cm_white()
{ //Check if white is in checkmate
    Position_set current_moves = find_all_moves_black();
    std::cerr << "ALL BLACK MOVES: " << current_moves << "\n";
    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++) {
            if(piece_at(j,i) == "WK"){
                if(current_moves[{i,j}]){
                    return true;
                }
            }
        }
    }

    return false;
}

Position_set
Model::find_all_moves_white()
{
    Position_set moves = {};

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (piece_at(j, i)[0] == 'W') {
                moves |= find_moves(piece_at(j, i), {i, j});
            }
        }
    }
    return moves;
}

Position_set
Model::find_all_moves_black()
{
    Position_set moves = {};

    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++) {
            if(piece_at(j,i)[0] == 'B'){
                moves |= find_moves(piece_at(j,i), {i,j});
            }
        }
    }

    return moves;
}

void
Model::set_selected(std::string piece)
{
    selected = piece;
}

std::string
Model::get_selected() const
{
    return selected;
}

void
Model::set_pos(Model::Position pos)
{
    current_pos = pos;
}

Model::Position
Model::get_pos() const
{
    return current_pos;
}

void
Model::set_piece_pos(Model::Position pos)
{
    piece_pos = pos;
}

Model::Position
Model::get_piece_pos() const
{
    return piece_pos;
}
Position_set Model::bp_valid_moves(Position pos)const
{
    Position_set pset = {};

    // If the pawn is at its starting row
    if (pos.y == 1) {
        if(piece_at(pos.y+1,pos.x) == " "){
            pset |= {{pos.x, pos.y + 1}};
        }
        if(piece_at(pos.y+2,pos.x) == " "){
            pset |={{pos.x, pos.y + 2}};
        }
        return pset;
    }

    //if there are enemies on its bottom left
    if (pos.x-1 >= 0 && piece_at(pos.y + 1, pos.x - 1)[0] == *"W"){
        pset |= {{pos.x - 1, pos.y + 1}};
    }

    //if there are enemies on its bottom right
    if (pos.x+1 < 8 && piece_at(pos.y + 1, pos.x + 1)[0] == *"W") {
        pset |= {{pos.x + 1, pos.y + 1}};
    }

    //if the space below the pawn is empty
    if (piece_at(pos.y + 1, pos.x) == " ") {
        pset |= {{pos.x, pos.y + 1}};
    }
    return pset;
}

Position_set Model::wp_valid_moves(Position pos)const
{

    Position_set pset = {};

    // If the pawn is at the starting row
    if (pos.y == 6) {
        if(piece_at(pos.y-1,pos.x) == " "){
            pset |= {{pos.x, pos.y - 1}};
        }
        if(piece_at(pos.y-2,pos.x) == " "){
            pset |={{pos.x, pos.y - 2}};
        }
        return pset;
    }

    //if there are enemies on its top left
    if (pos.x-1 >= 0 && piece_at(pos.y - 1, pos.x - 1)[0] == 'B'){
        pset |= {{pos.x - 1, pos.y - 1}};
    }

    //if there are enemies on its top right
    if (pos.x+1 < 8 && piece_at(pos.y - 1, pos.x + 1)[0] == 'B') {
        pset |= {{pos.x + 1, pos.y - 1}};
    }

    //if the space above the pawn is empty
    if (piece_at(pos.y-1, pos.x) == " ") {
        pset |= {{pos.x, pos.y - 1}};
    }


    return pset;
}
Position_set Model::br_valid_moves(Position pos)const
{

    Position_set pset = {};
    int i = 1;
    //upward movement
    while(pos.y - i >= 0 && piece_at(pos.y - i,pos.x)[0] != *"B"){
        pset |= {{pos.x,pos.y-i}};
        if(piece_at(pos.y-i,pos.x)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //downward movement
    while(pos.y + i < 8 && piece_at(pos.y+i,pos.x)[0] != *"B") {
        pset |= {{pos.x,pos.y + i}};
        if(piece_at(pos.y+i,pos.x)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //left movement
    while(pos.x - i >= 0 && piece_at(pos.y,pos.x-i)[0] != *"B") {
        pset |= {{pos.x - i,pos.y}};
        if(piece_at(pos.y,pos.x-i)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //right movement
    while(pos.x + i < 8 && piece_at(pos.y,pos.x+i)[0] != *"B") {
        pset |= {{pos.x + i,pos.y}};
        if(piece_at(pos.y,pos.x+i)[0] == *"W") {
            break;
        }
        i += 1;
    }
    return pset;
}

Position_set Model::wr_valid_moves(Position pos)const
{

    Position_set pset = {};
    int i = 1;
    //upward movement
    while(pos.y - i >= 0 && piece_at(pos.y-i,pos.x)[0] != *"W"){
        pset |= {{pos.x,pos.y-i}};
        if(piece_at(pos.y-i,pos.x)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //downward movement
    while(pos.y + i < 8 && piece_at(pos.y+i,pos.x)[0] != *"W") {
        pset |= {{pos.x,pos.y + i}};
        if(piece_at(pos.y+i,pos.x)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //left movement
    while(pos.x - i >= 0 && piece_at(pos.y,pos.x-i)[0] != *"W") {
        pset |= {{pos.x - i,pos.y}};
        if(piece_at(pos.y,pos.x-i)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //right movement
    while(pos.x + i < 8 && piece_at(pos.y,pos.x+i)[0] != *"W") {
        pset |= {{pos.x + i,pos.y}};
        if(piece_at(pos.y,pos.x+i)[0] == *"B") {
            break;
        }
        i += 1;
    }
    return pset;
}

Position_set Model::bn_valid_moves(Position pos)const
{

    Position_set pset = {};


    //Top right
    if (pos.x + 1 < 8 &&
        pos.y - 2 >= 0 &&
        piece_at(pos.y - 2, pos.x + 1)[0] != *"B"){
        pset |= {{pos.x + 1, pos.y - 2}};
    }
    //Top left
    if (pos.x - 1 >= 0 &&
        pos.y - 2 >= 0 &&
        piece_at(pos.y -2 , pos.x - 1)[0] != *"B"){
        pset |= {{pos.x - 1, pos.y - 2}};
    }
    //Bottom right
    if (pos.x + 1 < 8 &&
        pos.y + 2 < 8 &&
        piece_at(pos.y + 2, pos.x + 1)[0] != *"B"){
        pset |= {{pos.x + 1, pos.y + 2}};
    }
    //Bottom left
    if (pos.x - 1 >= 0 &&
        pos.y + 2 < 8 &&
        piece_at(pos.y + 2, pos.x - 1)[0] != *"B") {
        pset |= {{pos.x - 1, pos.y + 2}};
    }
    //Right top
    if (pos.x + 2 < 8 &&
        pos.y - 1 >= 0 &&
        piece_at(pos.y - 1, pos.x + 2)[0] != *"B") {
        pset |= {{pos.x + 2, pos.y - 1}};
    }
    //Right bottom
    if (pos.x + 2 < 8 &&
        pos.y + 1 < 8 &&
        piece_at(pos.y + 1, pos.x + 2)[0] != *"B") {
        pset |= {{pos.x + 2, pos.y + 1}};
    }
    //Left top
    if (pos.x - 2 >= 0 &&
        pos.y - 1 >= 0 &&
        piece_at(pos.y - 1, pos.x - 2)[0] != *"B") {
        pset |= {{pos.x - 2, pos.y - 1}};
    }
    //Left bottom
    if (pos.x - 2 >= 0 &&
        pos.y + 1 < 8 &&
        piece_at(pos.y + 1, pos.x - 2)[0] != *"B") {
        pset |= {{pos.x - 2, pos.y + 1}};
    }

    return pset;
}

Position_set Model::wn_valid_moves(Position pos)const
{
    Position_set pset = {};

    //Top right
    if (pos.x + 1 < 8 &&
        pos.y - 2 >= 0 &&
        piece_at(pos.y - 2, pos.x + 1)[0] != *"W"){
        pset |= {{pos.x + 1, pos.y - 2}};
    }
    //Top left
    if (pos.x - 1 >= 0 &&
        pos.y - 2 >= 0 &&
        piece_at(pos.y - 2, pos.x - 1)[0] != *"W"){
        pset |= {{pos.x - 1, pos.y - 2}};
    }
    //Bottom right
    if (pos.x + 1 < 8 &&
        pos.y + 2 < 8 &&
        piece_at(pos.y + 2, pos.x + 1)[0] != *"W"){
        pset |= {{pos.x + 1, pos.y + 2}};
    }
    //Bottom left
    if (pos.x - 1 >= 0 &&
        pos.y + 2 < 8 &&
        piece_at(pos.y + 2, pos.x - 1)[0] != *"W") {
        pset |= {{pos.x - 1, pos.y + 2}};
    }
    //Right top
    if (pos.x + 2 < 8 &&
        pos.y - 1 >= 0 &&
        piece_at(pos.y - 1, pos.x + 2)[0] != *"W") {
        pset |= {{pos.x + 2, pos.y - 1}};
    }
    //Right bottom
    if (pos.x + 2 < 8 &&
        pos.y + 1 < 8 &&
        piece_at(pos.y + 1, pos.x + 2)[0] != *"W") {
        pset |= {{pos.x + 2, pos.y + 1}};
    }
    //Left top
    if (pos.x - 2 >= 0 &&
        pos.y - 1 >= 0 &&
        piece_at(pos.y - 1, pos.x - 2)[0] != *"W") {
        pset |= {{pos.x - 2, pos.y - 1}};
    }
    //Left bottom
    if (pos.x - 2 >= 0 &&
        pos.y + 1 < 8 &&
        piece_at(pos.y + 1, pos.x - 2)[0] != *"W") {
        pset |= {{pos.x - 2, pos.y + 1}};
    }

    return pset;
}

Position_set Model::bb_valid_moves(Position pos)const
{
    Position_set pset = {};
    int i = 1;
    //top-right movement
    while(pos.x + i < 8 &&
          pos.y - i >= 0 &&
          piece_at(pos.y - i,pos.x + i)[0] != *"B"){
        pset |= {{pos.x + i,pos.y-i}};
        if(piece_at(pos.y - i,pos.x + i)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //top-left movement
    while(pos.x - i >= 0 &&
          pos.y - i >= 0 &&
          piece_at(pos.y - i,pos.x - i)[0] != *"B") {
        pset |= {{pos.x - i, pos.y - i}};
        if (piece_at(pos.y - i, pos.x - i)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //bottom-right movement
    while(pos.x + i < 8 &&
          pos.y + i < 8 &&
          piece_at(pos.y + i,pos.x + i)[0] != *"B") {
        pset |= {{pos.x + i, pos.y + i}};
        if (piece_at(pos.y + i, pos.x + i)[0] == *"W") {
            break;
        }
        i += 1;
    }
    i = 1;
    //bottom-left movement
    while(pos.x - i >= 0 &&
          pos.y + i < 8 &&
          piece_at(pos.y + i,pos.x - i)[0] != *"B") {
        pset |= {{pos.x - i, pos.y + i}};
        if (piece_at(pos.y + i, pos.x - i)[0] == *"W") {
            break;
        }
        i += 1;
    }

    return pset;
}

Position_set Model::wb_valid_moves(Position pos)const
{
    Position_set pset = {};
    int i = 1;
    //top-right movement
    while(pos.x + i < 8 &&
          pos.y - i >= 0 &&
          piece_at(pos.y - i,pos.x + i)[0] != *"W"){
        pset |= {{pos.x + i,pos.y-i}};
        if(piece_at(pos.y - i,pos.x + i)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //top-left movement
    while(pos.x - i >= 0 &&
          pos.y - i >= 0 &&
          piece_at(pos.y - i,pos.x - i)[0] != *"W") {
        pset |= {{pos.x - i, pos.y - i}};
        if (piece_at(pos.y - i, pos.x - i)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //bottom-right movement
    while(pos.x + i < 8 &&
          pos.y + i < 8 &&
          piece_at(pos.y + i,pos.x + i)[0] != *"W") {
        pset |= {{pos.x + i, pos.y + i}};
        if (piece_at(pos.y + i, pos.x + i)[0] == *"B") {
            break;
        }
        i += 1;
    }
    i = 1;
    //bottom-left movement
    while(pos.x - i >= 0 &&
          pos.y + i < 8 &&
          piece_at(pos.y + i,pos.x - i)[0] != *"W") {
        pset |= {{pos.x - i, pos.y + i}};
        if (piece_at(pos.y + i, pos.x - i)[0] == *"B") {
            break;
        }
        i += 1;
    }

    return pset;
}

Position_set Model::bq_valid_moves(Position pos) const
{
    Position_set pset = {};
    pset |= br_valid_moves(pos);
    pset |= bb_valid_moves(pos);
    return pset;
}

Position_set Model::wq_valid_moves(Position pos) const
{
    Position_set pset = {};
    pset |= wr_valid_moves(pos);
    pset |= wb_valid_moves(pos);
    return pset;
}

Position_set Model::bk_valid_moves(Position pos) const
{
    Position_set pset = {};
    //top left
    if(pos.x - 1 >= 0 &&
       pos.y - 1 >= 0 &&
       piece_at(pos.y -1,pos.x - 1)[0] != *"B"){
        pset |= {{pos.x - 1, pos.y - 1}};
    }
    //top
    if(pos.y - 1 >= 0 &&
       piece_at(pos.y - 1,pos.x)[0] != *"B"){
        pset |= {{pos.x, pos.y - 1}};
    }
    //top right
    if(pos.x + 1 < 8 &&
       pos.y - 1 >= 0 &&
       piece_at(pos.y - 1,pos.x + 1)[0] != *"B"){
        pset |= {{pos.x + 1, pos.y - 1}};
    }
    //middle left
    if(pos.x - 1 >= 0 &&
       piece_at(pos.y,pos.x - 1)[0] != *"B"){
        pset |= {{pos.x - 1, pos.y}};
    }
    //middle right
    if(pos.x + 1 < 8 &&
       piece_at(pos.y,pos.x + 1)[0] != *"B"){
        pset |= {{pos.x + 1, pos.y}};
    }
    //bottom left
    if(pos.x - 1 >= 0 &&
       pos.y + 1 < 8 &&
       piece_at(pos.y + 1,pos.x - 1)[0] != *"B"){
        pset |= {{pos.x - 1, pos.y + 1}};
    }
    //bottom
    if(pos.y + 1 < 8 &&
       piece_at(pos.y +1,pos.x)[0] != *"B"){
        pset |= {{pos.x, pos.y + 1}};
    }
    //bottom right
    if(pos.x + 1 < 8 &&
       pos.y + 1 < 8 &&
       piece_at(pos.y + 1,pos.x + 1)[0] != *"B"){
        pset |= {{pos.x + 1, pos.y + 1}};
    }

    return pset;
}

Position_set Model::wk_valid_moves(Position pos) const
{
    Position_set pset = {};
    //top left
    if(pos.x - 1 >= 0 &&
       pos.y - 1 >= 0 &&
       piece_at(pos.y -1,pos.x - 1)[0] != *"W"){
        pset |= {{pos.x - 1, pos.y - 1}};
    }
    //top
    if(pos.y - 1 >= 0 &&
       piece_at(pos.y - 1,pos.x)[0] != *"W"){
        pset |= {{pos.x, pos.y - 1}};
    }
    //top right
    if(pos.x + 1 < 8 &&
       pos.y - 1 >= 0 &&
       piece_at(pos.y - 1,pos.x + 1)[0] != *"W"){
        pset |= {{pos.x + 1, pos.y - 1}};
    }
    //middle left
    if(pos.x - 1 >= 0 &&
       piece_at(pos.y,pos.x - 1)[0] != *"W"){
        pset |= {{pos.x - 1, pos.y}};
    }
    //middle right
    if(pos.x + 1 < 8 &&
       piece_at(pos.y,pos.x + 1)[0] != *"W"){
        pset |= {{pos.x + 1, pos.y}};
    }
    //bottom left
    if(pos.x - 1 >= 0 &&
       pos.y + 1 < 8 &&
       piece_at(pos.y + 1,pos.x - 1)[0] != *"W"){
        pset |= {{pos.x - 1, pos.y + 1}};
    }
    //bottom
    if(pos.y + 1 < 8 &&
       piece_at(pos.y +1,pos.x)[0] != *"W"){
        pset |= {{pos.x, pos.y + 1}};
    }
    //bottom right
    if(pos.x + 1 < 8 &&
       pos.y + 1 < 8 &&
       piece_at(pos.y + 1,pos.x + 1)[0] != *"W"){
        pset |= {{pos.x + 1, pos.y + 1}};
    }

    return pset;
}

Position_set Model::find_moves(std::string piece, Model::Position pos) const
{
    if(piece == "BP") {
        return bp_valid_moves(pos);
    }
    if(piece == "BR") {
        return br_valid_moves(pos);
    }
    if(piece == "BN") {
        return bn_valid_moves(pos);
    }
    if(piece == "BB") {
        return bb_valid_moves(pos);
    }
    if(piece == "BQ") {
        return bq_valid_moves(pos);
    }
    if(piece == "BK") {
        return bk_valid_moves(pos);
    }
    if(piece == "WP") {
        return wp_valid_moves(pos);
    }
    if(piece == "WR") {
        return wr_valid_moves(pos);
    }
    if(piece == "WN") {
        return wn_valid_moves(pos);
    }
    if(piece == "WB") {
        return wb_valid_moves(pos);
    }
    if(piece == "WQ") {
        return wq_valid_moves(pos);
    }
    if(piece == "WK") {
        return wk_valid_moves(pos);
    }
    return {{}};
}

