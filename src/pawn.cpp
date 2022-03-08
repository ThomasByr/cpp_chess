#include "pawn.h"

Pawn::Pawn(int color, int file, int rank) : Piece(color, file, rank) {}

Pawn::~Pawn() {}

std::string Pawn::to_string() const {
    return color == Piece::White ? "\u2659" : "\u265F";
}

std::string Pawn::to_fen() const { return color == Piece::White ? "P" : "p"; }

std::vector<int> Pawn::get_targets(int board[64]) const {
    std::vector<int> targets;

    int pos = this->pos;
    int color = this->color;
    int file = FILE(pos), rank = RANK(pos);

    if (rank != (color == Piece::White ? 0 : 7)) {
        int t = pos + (color == Piece::White ? +8 : -8);
        if (board[t] == Piece::None) {
            targets.push_back(t);
        }
    }
    if (rank == (color == Piece::White ? 2 : 7)) {
        int t = pos + (color == Piece::White ? +16 : -16);
        if (board[t] == Piece::None) {
            targets.push_back(t);
        }
    }

    if (rank == (color == Piece::White ? 1 : 6)) {
        int other_color = color == Piece::White ? Piece::Black : Piece::White;
        for (int i : {-1, +1}) {
            if (file != (i == -1 ? 0 : 7) &&
                board[pos + i] == (other_color | Piece::Pawn)) {
                targets.push_back(pos + (color == Piece::White ? 8 : -8) + i);
            }
        }
    }

    if (rank != (color == Piece::White ? 0 : 7)) {
        int other_color = color == Piece::White ? Piece::Black : Piece::White;
        for (int i : {-1, +1}) {
            int t = pos + (color == Piece::White ? 8 : -8) + i;
            if (file != (i == -1 ? 0 : 7) &&
                (board[t] & Piece::color_mask) == other_color) {
                targets.push_back(t);
            }
        }
    }

    return targets;
}
