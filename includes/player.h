#pragma once

class Player {
  public:
    Player();
    virtual ~Player();

    virtual void play() = 0;

  protected:
    int score;
    int check_count;
};
