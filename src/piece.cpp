#include "piece.h"

Piece::Piece(int color, int x, int y) {
    this->color = color;
    this->pos = IX(x, y);
}

Piece::~Piece() {}

std::string Piece::to_string() const { return " "; }
