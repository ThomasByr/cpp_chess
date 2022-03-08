#include "piece.h"

Piece::Piece(int color, int file, int rank) {
    this->color = color;
    this->pos = IX(file, rank);

    moved = false;
}

Piece::~Piece() {}

std::string Piece::to_string() const { return " "; }

std::string Piece::to_fen() const { return " "; }

std::vector<int> Piece::get_targets(int board[64]) const {
    (void)board;
    return std::vector<int>();
}

bool Piece::is_inside(int pos) {
    if (pos < 0 || pos > 63) {
        return false;
    }
    int file = FILE(pos), rank = RANK(pos);
    return file >= 0 && file < 8 && rank >= 0 && rank < 8;
}

bool Piece::is_on_edge(int pos) {
    if (pos < 0 || pos > 63) {
        return false;
    }
    int file = FILE(pos), rank = RANK(pos);
    return file == 0 || file == 7 || rank == 0 || rank == 7;
}

// bool Piece::is_valid(int pos, int step) {
//     int file = FILE(pos), rank = RANK(pos);

//     if (step == -9) {
//         return file > 0 && rank > 0;
//     } else if (step == -8) {
//         return rank > 0;
//     } else if (step == -7) {
//         return file < 7 && rank > 0;
//     } else if (step == -1) {
//         return file > 0;
//     } else if (step == +1) {
//         return file < 7;
//     } else if (step == +7) {
//         return file > 0 && rank < 7;
//     } else if (step == +8) {
//         return rank < 7;
//     } else if (step == +9) {
//         return file < 7 && rank < 7;
//     } else if (step == -17) {
//         return file > 1 && rank > 2;
//     } else if (step == -15) {
//         return file < 6 && rank > 2;
//     } else if (step == -10) {
//         return file > 2 && rank > 1;
//     } else if (step == -6) {
//         return file < 5 && rank > 1;
//     } else if (step == +6) {
//         return file < 5 && rank < 6;
//     } else if (step == +10) {
//         return file > 2 && rank < 6;
//     } else if (step == +15) {
//         return file > 1 && rank < 5;
//     } else if (step == +17) {
//         return file < 6 && rank < 5;
//     } else {
//         return false;
//     }
// }

bool Piece::is_valid(int pos, int step) {
    int file = FILE(pos), rank = RANK(pos);

    int file_step = FILE(step), rank_step = RANK(step);
    switch (step) {
    case -7:
        file_step = 1;
        rank_step = -1;
        break;
    case 7:
        file_step = -1;
        rank_step = 1;
        break;
    case -6:
        file_step = 2;
        rank_step = -1;
        break;
    case 6:
        file_step = -2;
        rank_step = 1;
        break;
    }

    return file + file_step >= 0 && file + file_step < 8 &&
           rank + rank_step >= 0 && rank + rank_step < 8;
}
