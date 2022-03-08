#include "move.h"

Move::Move(const std::string &mv) {
    from = str_to_pos(mv.substr(0, 2));
    to = str_to_pos(mv.substr(2, 2));
}

Move::Move(int from, int to) {
    this->from = from;
    this->to = to;
}

Move::~Move() {}

int Move::str_to_pos(const std::string &str) {
    int rank, file;
    rank = str[1] - '1';
    file = str[0] - 'a';

    return IX(rank, file);
}
