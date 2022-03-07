#include "piece.h"

Piece::Piece(int color, int x, int y) {
    this->color = color;
    this->pos = IX(x, y);
}

Piece::~Piece() {}

std::string Piece::to_string() const { return " "; }

std::string Piece::to_fen() const { return " "; }

std::vector<int> Piece::get_targets(int board[64]) const {
    (void)board;
    return std::vector<int>();
}
