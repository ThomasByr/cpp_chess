#pragma once

#include "board.h"
#include "human.h"
#include "piece.h"
#include "player.h"

class Game {
  public:
    Game();
    ~Game();

    void clear_board();
    void load_from_fen(const std::string &fen);

    int piece_at(int file, int rank) const;

    void show();

    void play();

  private:
    Board *board;
    Player *player1; // white
    Player *player2; // black
};
