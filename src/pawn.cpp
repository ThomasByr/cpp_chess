#include "pawn.h"

Pawn::Pawn(int color, int x, int y) : Piece(color, x, y) {}

Pawn::~Pawn() {}

std::string Pawn::to_string() const {
    return color == Piece::White ? "\u2659" : "\u265F";
}
