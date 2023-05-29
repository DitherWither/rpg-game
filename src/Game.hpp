//
// Created by DitherWither on 5/29/23.
//

#ifndef RPG_GAME_GAME_HPP
#define RPG_GAME_GAME_HPP


#include "Player.hpp"
#include "Tileset.hpp"
#include "raylib.h"
#include "Map.hpp"

class Game {
private:
    void input();

    void update();

    void draw();

public:
    const float screenWidth;
    const float screenHeight;

    const int frameRate = 60;

    Player player;

    int frameCount;

    Tileset overworldTileset;
    Tileset caveTileset;

    Camera2D *camera;

    Map currentMap;

    Game(float screenWidth, float screenHeight, int frameRate);

    ~Game();

    void run();
};


#endif //RPG_GAME_GAME_HPP
