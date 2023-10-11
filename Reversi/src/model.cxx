#include "model.hxx"

using namespace ge211;

Model::Model(int size)
        : Model(size, size)
{ }

Model::Model(int width, int height)
        : board_({width, height})

{
    // TODO: initialize `next_moves_` to `turn_`'s available moves
    compute_next_moves_();
}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

Player
Model::operator[](Position pos) const
{
    return board_[pos];
}

const Move*
Model::find_move(Position pos) const
{
    auto i = next_moves_.find(pos);

    if (i == next_moves_.end()) {
        // Nothing was found, so return NULL (nullptr in C++)
        return nullptr;
    } else {
        // Dereferences the iterator to get the value then returns a pointer
        // to that value. This is safe as the pointer is to a value living
        // within the `next_moves_` structure.
        return &(*i);
    }
}

void
Model::play_move(Position pos)
{
    if (is_game_over()) {
        throw Client_logic_error("Model::play_move: game over");
    }

    const Move* movep = find_move(pos);
    if (movep == nullptr) { // check if there was no such move
        throw Client_logic_error("Model::play_move: no such move");
    }

    // TODO: actually execute the move, advance the turn, refill

    really_play_move_(*movep);
}

//
// BELOW ARE HELPER FUNCTIONS
// Our tests will run on the public functions, not the helper functions
// However, you are required to implement the following functions to help the
// public functions
//

Position_set
Model::find_flips_(Position current, Dimensions dir) const
{
    // TODO: HELPER FUNCTION
    Position_set empty_set = {};
    Position_set pset = {};

    while(true){
        current = current + dir;

        if(!board_.good_position(current) || board_[current] == Player::neither){
            return empty_set;
        }

        if(board_[current] == turn_) {
            return pset;
        }

        if(board_[current] == other_player(turn_)) {
            pset[current] = true;
        }
    }
}

Position_set
Model::evaluate_position_(Position pos) const
{
    // TODO: HELPER FUNCTION
    Position_set empty = {};
    Position_set pset = {};
    if (board_[pos] == Player::neither) {
        for (Dimensions dir: board_.all_directions()) {
            pset |= find_flips_(pos, dir);
        }
    }

    if(pset.empty()){
        return empty;
    }

    pset[pos] = true;

    return pset;
}

void
Model::compute_next_moves_()
{
    // TODO: HELPER FUNCTION
    next_moves_.clear();

    for (Position pos: board_.center_positions()) {
        if (board_[pos] == Player::neither) {
            next_moves_[pos] = {pos};
        }

    }
    if(next_moves_.empty()) {
        for (Position pos: board_.all_positions()) {
            Position_set pset = evaluate_position_(pos);

            if (!pset.empty()) {
                next_moves_[pos] = pset;
            }
        }
    }
}

bool
Model::advance_turn_()
{
    // TODO: HELPER FUNCTION
    turn_ = other_player(turn_);
    compute_next_moves_();

    return !next_moves_.empty(); // return if not empty
}

void
Model::set_game_over_()
{
    // TODO: HELPER FUNCTION
    turn_ = Player::neither;
    size_t black = board_.count_player(Player::dark);
    size_t white = board_.count_player(Player::light);

    if (black > white) {
        winner_ = Player::dark;
    }
    else if (white > black) {
        winner_ = Player::light;
    }
    else {
        winner_ = Player::neither;
    }
}

void
Model::really_play_move_(Move move)
{
    // TODO: HELPER FUNCTION
    Position_set gained = move.second;

    board_.set_all(gained, turn_);

    if (!advance_turn_()) {
        if(!advance_turn_()) {
            set_game_over_();
        }
    }
}
