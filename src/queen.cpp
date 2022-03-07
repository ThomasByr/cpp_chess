#include "queen.h"

Queen::Queen(int color, int x, int y) : Piece(color, x, y) {}

Queen::~Queen() {}

std::string Queen::to_string() const {
    return color == Piece::White ? "\u2655" : "\u265B";
}

std::string Queen::to_fen() const { return color == Piece::White ? "Q" : "q"; }

std::vector<Move> Queen::get_moves() const {
    std::vector<Move> moves = std::vector<Move>();

    return moves;
}
