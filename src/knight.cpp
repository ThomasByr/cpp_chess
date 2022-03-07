#include "knight.h"

Knight::Knight(int color, int x, int y) : Piece(color, x, y) {}

Knight::~Knight() {}

std::string Knight::to_string() const {
    return color == Piece::White ? "\u2658" : "\u265E";
}

std::string Knight::to_fen() const { return color == Piece::White ? "N" : "n"; }

std::vector<Move> Knight::get_moves() const {
    std::vector<Move> moves = std::vector<Move>();

    return moves;
}
