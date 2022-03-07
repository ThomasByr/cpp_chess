#pragma once

#include "piece.h"

class King : public Piece {
  public:
    King(int color, int x, int y);
    ~King();

    std::string to_string() const;

  private:
};
