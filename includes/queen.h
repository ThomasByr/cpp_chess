#pragma once

#include "piece.h"

class Queen : public Piece {
  public:
    Queen(int color, int x, int y);
    ~Queen();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<int> get_targets(int board[64]) const;

  private:
};
