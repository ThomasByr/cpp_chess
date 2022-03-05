#include <cctype>
#include <iostream>
#include <map>

#include "game.h"

Game::Game() {
    player1 = new Human();
    player2 = new Human();

    load_from_fen(fen_start);
}

Game::~Game() {
    delete player1;
    delete player2;
}

int Game::piece_at(int file, int rank) const { return board[rank][file]; }

void Game::clear_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = Piece::None;
        }
    }
}

void Game::load_from_fen(const std::string &fen) {
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
                board[rank][file] = color | piece;
                file++;
            }
        }
    }
};
