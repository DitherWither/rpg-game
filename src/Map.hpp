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
    Tileset *caveTileset;
    std::vector<std::vector<int>> mapContents;
    std::vector<std::vector<std::string>> mapStyles;
    std::string filename;


public:
    Map(Tileset* overworldTileset, Tileset* caveTileset, std::string filename);
    void draw();
};


#endif //RPG_GAME_MAP_HPP
