#include "king.h"

King::King(int color, int x, int y) : Piece(color, x, y) {}

King::~King() {}

std::string King::to_string() const {
    return color == Piece::White ? "\u2654" : "\u265A";
}
