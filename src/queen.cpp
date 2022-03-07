#include "queen.h"

Queen::Queen(int color, int x, int y) : Piece(color, x, y) {}

Queen::~Queen() {}

std::string Queen::to_string() const {
    return color == Piece::White ? "\u2655" : "\u265B";
}

std::string Queen::to_fen() const { return color == Piece::White ? "Q" : "q"; }

std::vector<int> Queen::get_targets(int board[64]) const {
    std::vector<int> targets;
    (void)board;

    return targets;
}
