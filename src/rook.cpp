#include "rook.h"

Rook::Rook(int color, int x, int y) : Piece(color, x, y) {}

Rook::~Rook() {}

std::string Rook::to_string() const {
    return color == Piece::White ? "\u2656" : "\u265C";
}

std::string Rook::to_fen() const { return color == Piece::White ? "R" : "r"; }

std::vector<int> Rook::get_targets(int board[64]) const {
    std::vector<int> targets;
    (void)board;

    return targets;
}
