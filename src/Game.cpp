//
// Created by DitherWither on 5/29/23.
//

#include "Game.hpp"
#include "Player.hpp"
#include "Tileset.hpp"
#include <raylib.h>

Game::Game(float screenWidth, float screenHeight, int frameRate)
        : screenWidth(screenWidth), screenHeight(screenHeight),
          frameRate(frameRate),
          player(Player(screenWidth, screenHeight, &frameCount)), frameCount(0),
          overworldTileset(Tileset("assets/sprites/overworld.png", 16, 16)),
          camera(&player.camera) {}

void Game::run() {
    while (!WindowShouldClose()) {
        input();
        update();
        draw();
    }
}

Game::~Game() { CloseWindow(); }

void Game::input() { player.input(); }

void Game::update() {
    frameCount++;
    player.update();
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLUE);

    BeginMode2D(*camera);

    overworldTileset.draw(0, 0, 0);

    player.draw();

    EndMode2D();
    EndDrawing();
}
