#include "Game.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int FRAME_RATE = 60;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");
    SetTargetFPS(FRAME_RATE);

    Game game = Game(SCREEN_WIDTH, SCREEN_HEIGHT, FRAME_RATE);

    game.run();

    return 0;
}
