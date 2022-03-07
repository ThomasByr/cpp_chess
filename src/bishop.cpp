#include "bishop.h"

Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {}

Bishop::~Bishop() {}

std::string Bishop::to_string() const {
    return color == Piece::White ? "\u2657" : "\u265D";
}

std::string Bishop::to_fen() const { return color == Piece::White ? "B" : "b"; }

std::vector<int> Bishop::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;

    for (int t : {-9, -7, +7, +9}) {
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
