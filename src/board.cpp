#include <cctype>
#include <iostream>
#include <map>

#include "board.h"
#include "protocol.h"

Board::Board() { load_from_fen(fen_start); }

Board::~Board() { clear_board(); }

int Board::piece_at(int file, int rank) const { return board[IX(file, rank)]; }

void Board::clear_board() {
    for (int i = 0; i < 64; i++) {
        board[i] = Piece::None;
    }

    for (auto const &piece : pieces) {
        delete piece.second;
    }

    pieces.clear();
    white_pieces.clear();
    black_pieces.clear();

    white_controlled_squares.clear();
    black_controlled_squares.clear();
}

void Board::make_pieces() {
    for (int index = 0; index < 64; index++) {
        int piece = board[index];
        if (piece == Piece::None) {
            continue;
        }

        int file = FILE(index);
        int rank = RANK(index);

        int color = piece & Piece::color_mask;
        int type = piece & Piece::type_mask;

        Piece *p = nullptr;
        switch (type) {
        case Piece::Pawn:
            p = new Pawn(color, file, rank);
            break;
        case Piece::Knight:
            p = new Knight(color, file, rank);
            break;
        case Piece::Bishop:
            p = new Bishop(color, file, rank);
            break;
        case Piece::Rook:
            p = new Rook(color, file, rank);
            break;
        case Piece::Queen:
            p = new Queen(color, file, rank);
            break;
        case Piece::King:
            p = new King(color, file, rank);
            break;
        }

        if (p != nullptr) {
            pieces[index] = p;
            if (color == Piece::White) {
                white_pieces[index] = p;
            } else {
                black_pieces[index] = p;
            }
        }
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

    make_pieces();
}

void Board::show() {
    std::cout << "   ";
    for (int file = 0; file < 8; file++) {
        std::cout << (char)('a' + file) << "  ";
    }
    std::cout << "\n  ------------------------\n";

    for (int rank = 7; rank >= 0; rank--) {
        std::cout << rank + 1 << "|";
        for (int file = 0; file < 8; file++) {
            int p = piece_at(file, rank);

            if (p == Piece::None) {
                std::cout << "   ";
            } else {
                Piece *piece = pieces[IX(file, rank)];
                std::cout << " " << piece->to_string() << " ";
            }
        }
        std::cout << "\n";
    }
}
