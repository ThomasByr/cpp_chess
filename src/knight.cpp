#include "knight.h"

Knight::Knight(int color, int x, int y) : Piece(color, x, y) {}

Knight::~Knight() {}

std::string Knight::to_string() const {
    return color == Piece::White ? "\u2658" : "\u265E";
}

std::string Knight::to_fen() const { return color == Piece::White ? "N" : "n"; }

std::vector<int> Knight::get_targets(int board[64]) const {
    std::vector<int> targets;
    (void)board;

    return targets;
}
