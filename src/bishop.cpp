#include "bishop.h"

Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {}

Bishop::~Bishop() {}

std::string Bishop::to_string() const {
    return color == Piece::White ? "\u2657" : "\u265D";
}

std::string Bishop::to_fen() const { return color == Piece::White ? "B" : "b"; }

std::vector<Move> Bishop::get_moves() const {
    std::vector<Move> moves = std::vector<Move>();

    return moves;
}
