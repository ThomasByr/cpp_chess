#include <iostream>
#include <vector>

#include "macros.h"
#include "piece.h"
#include "protocol.h"

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

void piece_test_0() {
    int board[64] = {0};

    board[IX(0, 0)] = Piece::White | Piece::Rook;
    board[IX(1, 0)] = Piece::White | Piece::Knight;
    board[IX(2, 0)] = Piece::White | Piece::Bishop;
    board[IX(3, 0)] = Piece::White | Piece::Queen;
    board[IX(4, 0)] = Piece::White | Piece::King;
    board[IX(5, 0)] = Piece::White | Piece::Bishop;
    board[IX(6, 0)] = Piece::White | Piece::Knight;
    board[IX(7, 0)] = Piece::White | Piece::Rook;

    for (int i = 0; i < 8; i++) {
        board[IX(i, 1)] = Piece::White | Piece::Pawn;
    }

    board[IX(0, 7)] = Piece::Black | Piece::Rook;
    board[IX(1, 7)] = Piece::Black | Piece::Knight;
    board[IX(2, 7)] = Piece::Black | Piece::Bishop;
    board[IX(3, 7)] = Piece::Black | Piece::Queen;
    board[IX(4, 7)] = Piece::Black | Piece::King;
    board[IX(5, 7)] = Piece::Black | Piece::Bishop;
    board[IX(6, 7)] = Piece::Black | Piece::Knight;
    board[IX(7, 7)] = Piece::Black | Piece::Rook;

    for (int i = 0; i < 8; i++) {
        board[IX(i, 6)] = Piece::Black | Piece::Pawn;
    }

    Queen queen = Queen(Piece::White, 3, 0);
    std::vector<int> targets = queen.get_targets(board);

    for (auto target : targets) {
        assert_eq(board[target], Piece::None);
    }

    assert_eq(targets.size(), 0);
}

void test_piece_1() {
    int board[64] = {0};
    Queen queen = Queen(Piece::White, 3, 3);

    board[IX(3, 3)] = Piece::White | Piece::Queen;

    std::vector<int> targets = queen.get_targets(board);

    for (auto target : targets) {
        assert(Piece::is_inside(target));
        assert_eq(board[target], Piece::None);
    }

    assert_eq(targets.size(), 27);
}

void piece_test_2() {
    int board[64] = {0};
    Queen queen = Queen(Piece::White, 3, 0);

    board[IX(3, 0)] = Piece::White | Piece::Queen;

    std::vector<int> targets = queen.get_targets(board);

    for (auto target : targets) {
        assert(Piece::is_inside(target));
        assert_eq(board[target], Piece::None);
    }

    assert_eq(targets.size(), 21);
}

void piece_test() {
    test_case(piece_test_0);
    test_case(test_piece_1);
    test_case(piece_test_2);
}
