#include "bishop.h"

Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {}

Bishop::~Bishop() {}

std::string Bishop::to_string() const {
    return color == Piece::White ? "\u2657" : "\u265D";
}

std::string Bishop::to_fen() const { return color == Piece::White ? "B" : "b"; }

std::vector<int> Bishop::get_targets(int board[64]) const {
    std::vector<int> targets;
    (void)board;

    return targets;
}
