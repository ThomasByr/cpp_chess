#pragma once

#include <string>

#include "protocol.h"

class Move {
  public:
    Move(const std::string &mv);
    ~Move();

    int str_to_pos(const std::string &mv) const;

  private:
    int from;
    int to;
};
