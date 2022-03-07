#pragma once

#include "piece.h"

class Rook : public Piece {
  public:
    Rook(int color, int x, int y);
    ~Rook();

    std::string to_string() const;

  private:
};
