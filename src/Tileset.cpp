//
// Created by DitherWither on 5/29/23.
//

#include "Tileset.hpp"

#include <raylib.h>
#include <string>

Tileset::Tileset(const std::string &filename, int tileWidth, int tileHeight)
        : texture(LoadTexture(filename.c_str())), tileWidth(tileWidth),
          tileHeight(tileHeight) {}

Tileset::~Tileset() { UnloadTexture(texture); }

void Tileset::draw(int tileIndex, int x, int y) {
    int tileX = tileIndex % (texture.width / tileWidth);
    int tileY = tileIndex / (texture.width / tileWidth);

    Rectangle sourceRect = {static_cast<float>(tileX * tileWidth),
                            static_cast<float>(tileY * tileHeight),
                            static_cast<float>(tileWidth),
                            static_cast<float>(tileHeight)};
    Rectangle destRect = {static_cast<float>(x), static_cast<float>(y),
                          static_cast<float>(tileWidth),
                          static_cast<float>(tileHeight)};

    DrawTexturePro(
            texture, sourceRect, destRect,
            {static_cast<float>(tileWidth), static_cast<float>(tileHeight)}, 0.0f,
            WHITE);
}
