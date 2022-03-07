#pragma once

#include <string>
#include <unordered_set>
#include <vector>

#include "move.h"
#include "protocol.h"

class Piece {
  public:
    inline static const int None = 0;
    inline static const int King = 1;
    inline static const int Pawn = 2;
    inline static const int Knight = 3;
    inline static const int Bishop = 4;
    inline static const int Rook = 5;
    inline static const int Queen = 6;

    inline static const int White = 8;
    inline static const int Black = 16;

    inline static const int type_mask = 7;
    inline static const int color_mask = 24;

    Piece(int color, int x, int y);
    virtual ~Piece();

    bool is_inside(int pos) const;

    virtual std::string to_string() const = 0;
    virtual std::string to_fen() const = 0;

    virtual std::vector<int> get_targets(int board[64]) const = 0;

  protected:
    int pos;
    int color;
    std::unordered_set<int> controlled_squares;
};
