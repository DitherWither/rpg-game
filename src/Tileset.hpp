//
// Created by DitherWither on 5/29/23.
//

#ifndef RPG_GAME_TILESET_HPP
#define RPG_GAME_TILESET_HPP

#include <raylib.h>
#include <string>

class Tileset {
public:
    const Texture2D texture;
    const int tileWidth;
    const int tileHeight;

    Tileset(const std::string &filename, int tileWidth, int tileHeight);

    ~Tileset();

    void draw(int tileIndex, int x, int y);
};

#endif //RPG_GAME_TILESET_HPP
