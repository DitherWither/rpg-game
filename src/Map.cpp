//
// Created by DitherWither on 5/29/23.
//

#include "Map.hpp"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

auto read_file(std::string_view path) -> std::string {
    constexpr auto read_size = std::size_t(4096);
    auto stream = std::ifstream(path.data());
    stream.exceptions(std::ios_base::badbit);

    if (not stream) {
        throw std::ios_base::failure("file does not exist");
    }

    auto out = std::string();
    auto buf = std::string(read_size, '\0');
    while (stream.read(& buf[0], read_size)) {
        out.append(buf, 0, stream.gcount());
    }
    out.append(buf, 0, stream.gcount());
    return out;
}

Map::Map(Tileset *overworldTileset, std::string filename) : overworldTileset(overworldTileset), filename(filename) {
    this->mapContents = {{0, 0, 0, 0},
                         {0, 19, 19, 0},
                         {0, 19, 0, 0, 0},
                         {0, 0, 0, 0}};

    // Load file into a string
    std::string fileString = read_file(filename);
    json fileJson = json::parse(fileString);

    this -> mapContents = fileJson["tiles"].get<std::vector<std::vector<int>>>();
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


