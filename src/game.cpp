#include <cctype>
#include <iostream>
#include <map>

#include "game.h"

Game::Game() {
    player1 = new Human();
    player2 = new Human();

    board = new Board();
}

Game::~Game() {
    delete player1;
    delete player2;

    delete board;
}

int Game::piece_at(int file, int rank) const {
    return board->piece_at(file, rank);
}

void Game::show() { board->show(); }
