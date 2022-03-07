#pragma once

#include <map>
#include <string>
#include <unordered_set>
#include <vector>

#include "move.h"
#include "piece.h"

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

static const std::string &fen_start =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

class Board {
  public:
    Board();
    ~Board();
    void make_move(const Move &move);
    void unmake_move(const Move &move);

    void clear_board();
    void load_from_fen(const std::string &fen);
    void make_pieces();

    int piece_at(int file, int rank) const;

    void show();

  private:
    int board[64];
    int map[64][6];

    std::map<int, Piece *> pieces;
    std::map<int, Piece *> white_pieces;
    std::map<int, Piece *> black_pieces;

    std::unordered_set<int> white_controlled_squares;
    std::unordered_set<int> black_controlled_squares;
};
