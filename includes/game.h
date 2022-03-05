#pragma once

#include "human.h"
#include "piece.h"
#include "player.h"

#include <iostream>
#include <string>

static const std::string &fen_start =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

class Game {
  public:
    Game();
    ~Game();

    void clear_board();
    void load_from_fen(const std::string &fen);

    int piece_at(int file, int rank) const;

    void play();

  private:
    int board[8][8];
    Player *player1; // white
    Player *player2; // black
};
