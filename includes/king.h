#pragma once

#include "piece.h"

class King : public Piece {
  public:
    King(int color, int x, int y);
    ~King();

    std::string to_string() const;
    std::string to_fen() const;

    std::vector<Move> get_moves() const;

  private:
};
