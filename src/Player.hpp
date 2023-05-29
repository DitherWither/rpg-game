//
// Created by DitherWither on 5/29/23.
//

#ifndef RPG_GAME_PLAYER_HPP
#define RPG_GAME_PLAYER_HPP

#include <raylib.h>

enum class Direction {
    UP = 2, DOWN = 0, LEFT = 3, RIGHT = 1
};

class Player {

public:
    const Texture2D texture;
    const float screenWidth;
    const float screenHeight;

    Rectangle sourceRect;
    Rectangle destRect;

    int *frameCount;

    bool isMovingUp = false;
    bool isMovingDown = false;
    bool isMovingLeft = false;
    bool isMovingRight = false;

    // Is separate from the isMoving* variables because the player can be
    // moving diagonally
    Direction direction = Direction::DOWN;

    bool isSprinting = false;

    const float baseSpeed = 2.0f;

    Camera2D camera;

    Player(float screenWidth, float screenHeight, int *frameCount);

    ~Player();

    void draw();

    void input();

    void update();
};


#endif //RPG_GAME_PLAYER_HPP
