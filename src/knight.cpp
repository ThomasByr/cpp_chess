#include "knight.h"

Knight::Knight(int color, int x, int y) : Piece(color, x, y) {}

Knight::~Knight() {}

std::string Knight::to_string() const {
    return color == Piece::White ? "\u2658" : "\u265E";
}
