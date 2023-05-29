//
// Created by DitherWither on 5/29/23.
//

#include "Player.hpp"
#include <raylib.h>

Player::Player(float screenWidth, float screenHeight, int *frameCount)
        : texture(LoadTexture("assets/sprites/character.png")), screenWidth(screenWidth),
          screenHeight(screenHeight), sourceRect({0.0f, 0.0f, 16.0f, 32.0f}),
          destRect({0.0f, 0.0f, 16.0f, 32.0f}), frameCount(frameCount),
          camera({{screenWidth / 2, screenHeight / 2},
                  {destRect.x - (destRect.width / 2),
                   destRect.y - (destRect.height / 2)},
                  0.0f,
                  6.0f}) {}

Player::~Player() { UnloadTexture(texture); }

void Player::draw() {
    // TODO - make the player face the direction they are moving
    DrawTexturePro(texture, sourceRect, destRect,
                   {destRect.width, destRect.height}, 0.0f, WHITE);
}

void Player::input() {
    isMovingUp = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
    isMovingDown = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
    isMovingLeft = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
    isMovingRight = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);

    isSprinting = IsKeyDown(KEY_LEFT_SHIFT);
}

void Player::update() {
    float speed = baseSpeed * (isSprinting ? 2.0f : 1.0f);

    bool moved = false;

    if (isMovingLeft) {
        destRect.x -= speed;
        moved = true;

        direction = Direction::LEFT;
    }
    if (isMovingRight) {
        destRect.x += speed;
        moved = true;

        direction = Direction::RIGHT;
    }

    if (isMovingUp) {
        destRect.y -= speed;
        moved = true;

        direction = Direction::UP;
    }
    if (isMovingDown) {
        destRect.y += speed;
        moved = true;

        direction = Direction::DOWN;
    }

    // switch the sprite every 10 frames
    if (moved) {
        if (*frameCount % 10 == 0) {
            sourceRect.x = (float) (16 * ((int) *frameCount / 10 % 4));
        }
    } else {
        sourceRect.x = 0;
        // TODO idle animation
    }

    sourceRect.y = (float) (32 * (int) direction);

    camera.target = {destRect.x - (destRect.width / 2),
                     destRect.y - (destRect.height / 2)};
}

