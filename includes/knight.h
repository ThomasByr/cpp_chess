#pragma once

#include "piece.h"

class Knight : public Piece {
  public:
    Knight(int color, int x, int y);
    ~Knight();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<Move> get_moves() const;

  private:
};
