#pragma once

#include "piece.h"

class Queen : public Piece {
  public:
    Queen(int color, int x, int y);
    ~Queen();

    std::string to_string() const;

  private:
};
