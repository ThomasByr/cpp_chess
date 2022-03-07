#include "bishop.h"

Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {}

Bishop::~Bishop() {}

std::string Bishop::to_string() const {
    return color == Piece::White ? "\u2657" : "\u265D";
}
