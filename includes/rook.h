#pragma once

#include "piece.h"

class Rook : public Piece {
  public:
    Rook(int color, int file, int rank);
    ~Rook();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<int> get_targets(int board[64]) const;

  private:
};
