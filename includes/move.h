#pragma once

#include <string>

#include "protocol.h"

class Move {
  public:
    Move(const std::string &mv);
    Move(int from, int to);
    ~Move();

    static int str_to_pos(const std::string &mv);

  private:
    int from;
    int to;
};
