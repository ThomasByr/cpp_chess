#include "game.h"
#include "macros.h"
#include "piece.h"

void game_test_0() {
    Game game = Game();

    int board[8][8] = {0};

    board[0][0] = Piece::White | Piece::Rook;
    board[0][1] = Piece::White | Piece::Knight;
    board[0][2] = Piece::White | Piece::Bishop;
    board[0][3] = Piece::White | Piece::Queen;
    board[0][4] = Piece::White | Piece::King;
    board[0][5] = Piece::White | Piece::Bishop;
    board[0][6] = Piece::White | Piece::Knight;
    board[0][7] = Piece::White | Piece::Rook;

    for (int i = 0; i < 8; i++) {
        board[1][i] = Piece::White | Piece::Pawn;
    }

    board[7][0] = Piece::Black | Piece::Rook;
    board[7][1] = Piece::Black | Piece::Knight;
    board[7][2] = Piece::Black | Piece::Bishop;
    board[7][3] = Piece::Black | Piece::Queen;
    board[7][4] = Piece::Black | Piece::King;
    board[7][5] = Piece::Black | Piece::Bishop;
    board[7][6] = Piece::Black | Piece::Knight;
    board[7][7] = Piece::Black | Piece::Rook;

    for (int i = 0; i < 8; i++) {
        board[6][i] = Piece::Black | Piece::Pawn;
    }

    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            assert_eq(game.piece_at(file, rank), board[rank][file]);
        }
    }
}

void game_test() { test_case(game_test_0); }
