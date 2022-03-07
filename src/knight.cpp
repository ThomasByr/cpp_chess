#include "knight.h"

Knight::Knight(int color, int file, int rank) : Piece(color, file, rank) {}

Knight::~Knight() {}

std::string Knight::to_string() const {
    return color == Piece::White ? "\u2658" : "\u265E";
}

std::string Knight::to_fen() const { return color == Piece::White ? "N" : "n"; }

std::vector<int> Knight::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;

    for (int t : {-17, -15, -10, -6, +6, +10, +15, +17}) {
        int i = pos + t;
        if (is_inside(i) && ((board[i] == Piece::None) ||
                             (board[i] & Piece::color_mask) != color)) {
            targets.push_back(i);
        }
    }

    return targets;
}
