#include "rook.h"

Rook::Rook(int color, int x, int y) : Piece(color, x, y) {}

Rook::~Rook() {}

std::string Rook::to_string() const {
    return color == Piece::White ? "\u2656" : "\u265C";
}

std::string Rook::to_fen() const { return color == Piece::White ? "R" : "r"; }

std::vector<int> Rook::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;

    for (int t : {-8, -1, +1, +8}) {
        int i = pos + t;
        while (is_inside(i) && ((board[i] == Piece::None) ||
                                (board[i] & Piece::color_mask) != color)) {
            targets.push_back(i);
            i += t;

            if (board[i] != Piece::None) {
                break;
            }
        }
    }

    return targets;
}
