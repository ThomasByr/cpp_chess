#include "rook.h"

Rook::Rook(int color, int x, int y) : Piece(color, x, y) {}

Rook::~Rook() {}

std::string Rook::to_string() const {
    return color == Piece::White ? "\u2656" : "\u265C";
}
