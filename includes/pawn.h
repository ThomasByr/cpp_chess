#pragma once

#include "piece.h"

class Pawn : public Piece {
  public:
    Pawn(int color, int file, int rank);
    ~Pawn();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<int> get_targets(int board[64]) const;

  private:
};
