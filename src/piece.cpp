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

bool Piece::is_inside(int pos) const {
    int file = FILE(pos), rank = RANK(pos);
    return file >= 0 && file < 8 && rank >= 0 && rank < 8;
}
