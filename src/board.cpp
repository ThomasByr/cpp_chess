#include <cctype>
#include <iostream>
#include <map>

#include "board.h"
#include "protocol.h"

Board::Board() { load_from_fen(fen_start); }

Board::~Board() {}

int Board::piece_at(int file, int rank) const { return board[IX(file, rank)]; }

void Board::clear_board() {
    for (int i = 0; i < 64; i++) {
        board[i] = Piece::None;
    }
}

void Board::load_from_fen(const std::string &fen) {
    static const std::map<char, int> piece_map = {
        {'k', Piece::King},   {'q', Piece::Queen},  {'r', Piece::Rook},
        {'b', Piece::Bishop}, {'n', Piece::Knight}, {'p', Piece::Pawn},
    };

    clear_board();

    std::string fen_board = fen.substr(0, fen.find(' '));
    int file = 0, rank = 7;

    for (const unsigned char c : fen_board) {
        if (c == '/') {
            file = 0;
            rank--;
        } else {
            if (isdigit(c)) {
                file += c - '0';
            } else {
                int piece = piece_map.at(tolower(c));
                int color = isupper(c) ? Piece::White : Piece::Black;
                board[IX(file, rank)] = color | piece;
                file++;
            }
        }
    }
};
