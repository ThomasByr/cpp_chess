#pragma once

#include <unordered_set>

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

  protected:
    int pos;
    std::unordered_set<int> controlled_squares;
};
