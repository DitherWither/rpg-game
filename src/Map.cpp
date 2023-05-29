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

Map::Map(Tileset *overworldTileset, Tileset* caveTileset, std::string filename) : overworldTileset(overworldTileset), filename(filename), caveTileset(caveTileset) {
    // Load file into a string
    std::string fileString = read_file(filename);
    json fileJson = json::parse(fileString);

    this -> mapContents = fileJson["tiles"].get<std::vector<std::vector<int>>>();
    this -> mapStyles = fileJson["style"].get<std::vector<std::vector<std::string>>>();
}

void Map::draw() {
    for (int column = 0; column < this->mapContents.size(); column++) {
        for (int row = 0; row < this->mapContents[column].size(); row++) {
            int xpos = row * this->overworldTileset->tileWidth;
            int ypos = column * this->overworldTileset->tileHeight;

            if (mapStyles[column][row] == "o")
            overworldTileset->draw(mapContents[column][row], xpos, ypos);
            else if (mapStyles[column][row] == "c")
                caveTileset->draw(mapContents[column][row], xpos, ypos);

        }
    }
}


