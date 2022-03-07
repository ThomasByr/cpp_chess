#include "king.h"

King::King(int color, int x, int y) : Piece(color, x, y) {}

King::~King() {}

std::string King::to_string() const {
    return color == Piece::White ? "\u2654" : "\u265A";
}

std::string King::to_fen() const { return color == Piece::White ? "K" : "k"; }

std::vector<Move> King::get_moves() const {
    std::vector<Move> moves = std::vector<Move>();

    return moves;
}
