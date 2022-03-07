#pragma once

#include "piece.h"

class Rook : public Piece {
  public:
    Rook(int color, int x, int y);
    ~Rook();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<Move> get_moves() const;

  private:
};
