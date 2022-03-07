#pragma once

#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(int color, int x, int y);
    ~Bishop();

    std::string to_string() const;

  private:
};
