//
// Created by DitherWither on 5/29/23.
//

#ifndef RPG_GAME_MAP_HPP
#define RPG_GAME_MAP_HPP

#include <raylib.h>
#include <vector>
#include "Tileset.hpp"

class Map {
private:
    Tileset *overworldTileset;
    std::vector<std::vector<int>> mapContents;

public:
    Map(Tileset* overworldTileset);
    void draw();
};


#endif //RPG_GAME_MAP_HPP
