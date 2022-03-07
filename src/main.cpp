#include <iostream>

#include "game.h"

using namespace std;

int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;

    Game game = Game();

    game.show();
    return 0;
}
