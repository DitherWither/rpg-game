//
// Created by vardhan on 5/29/23.
//

#ifndef RPG_GAME_MAPLAYER_HPP
#define RPG_GAME_MAPLAYER_HPP

#include <vector>
#include <string>

class MapLayer {
public:
    std::vector<std::vector<int>> tiles;
    std::vector<std::vector<std::string>> style;
};


#endif //RPG_GAME_MAPLAYER_HPP
