//
// Created by DitherWither on 5/29/23.
//

#include "Map.hpp"

Map::Map(Tileset *overworldTileset) : overworldTileset(overworldTileset) {
    this->mapContents = {{0, 0, 0, 0},
                         {0, 19, 19, 0},
                         {0, 19, 0, 0, 0},
                         {0, 0, 0, 0}};
}

void Map::draw() {
    for (int column = 0; column < this->mapContents.size(); column++) {
        for (int row = 0; row < this->mapContents[column].size(); row++) {
            int xpos = row * this->overworldTileset->tileWidth;
            int ypos = column * this->overworldTileset->tileHeight;

            overworldTileset->draw(mapContents[column][row], xpos, ypos);
        }
    }
}


