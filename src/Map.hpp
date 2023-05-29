//
// Created by DitherWither on 5/29/23.
//

#ifndef RPG_GAME_MAP_HPP
#define RPG_GAME_MAP_HPP

#include <raylib.h>
#include <vector>
#include "Tileset.hpp"

class MapLayer {
public:
    std::vector<std::vector<int>> tiles;
    std::vector<std::vector<std::string>> style;
    void draw();
};

class Map {
private:
    Tileset *overworldTileset;
    Tileset *caveTileset;
    Tileset *innerTileset;

    std::vector<MapLayer> layers;
    std::string filename;


public:
    Map(Tileset *overworldTileset, Tileset *caveTileset, Tileset* innerTileset, std::string filename);

    void draw();
};


#endif //RPG_GAME_MAP_HPP
