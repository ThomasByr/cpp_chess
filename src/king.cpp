#include "king.h"

King::King(int color, int file, int rank) : Piece(color, file, rank) {}

King::~King() {}

std::string King::to_string() const {
    return color == Piece::White ? "\u2654" : "\u265A";
}

std::string King::to_fen() const { return color == Piece::White ? "K" : "k"; }

std::vector<int> King::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;

    for (int t : {-9, -8, -7, -1, +1, +7, +8, +9}) {
        int i = pos + t;
        if (is_inside(i) && ((board[i] == Piece::None) ||
                             (board[i] & Piece::color_mask) != color)) {
            targets.push_back(i);
        }
    }

    return targets;
}
