#include "queen.h"

Queen::Queen(int color, int x, int y) : Piece(color, x, y) {}

Queen::~Queen() {}

std::string Queen::to_string() const {
    return color == Piece::White ? "\u2655" : "\u265B";
}

std::string Queen::to_fen() const { return color == Piece::White ? "Q" : "q"; }

std::vector<int> Queen::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;

    for (int t : {-9, -8, -7, -1, +1, +7, +8, +9}) {
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
