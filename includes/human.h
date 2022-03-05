#pragma once

#include "player.h"

class Human : public Player {
  public:
    Human();
    ~Human();

    void play();
};
