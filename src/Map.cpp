//
// Created by DitherWither on 5/29/23.
//

#include "Map.hpp"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

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
    while (stream.read(&buf[0], read_size)) {
        out.append(buf, 0, stream.gcount());
    }
    out.append(buf, 0, stream.gcount());
    return out;
}

Map::Map(Tileset *overworldTileset, Tileset *caveTileset, Tileset *innerTileset, std::string filename)
        : overworldTileset(overworldTileset), filename(filename), caveTileset(caveTileset), innerTileset(innerTileset) {
    // Load file into a string
    std::string fileString = read_file(filename);
    json fileJson = json::parse(fileString);

    std::vector<json> layersJson = fileJson["layers"].get<std::vector<json>>();

    for (auto layerJson: layersJson) {
        MapLayer layer;

        layer.tiles = layerJson["tiles"].get<std::vector<std::vector<int>>>();
        layer.style = layerJson["style"].get<std::vector<std::vector<std::string>>>();
        this->layers.push_back(layer);
    }
}


void Map::draw() {
    for (auto layer: this->layers) {
        for (int column = 0; column < layer.tiles.size(); column++) {
            for (int row = 0; row < layer.tiles[column].size(); row++) {
                int xpos = row * this->overworldTileset->tileWidth;
                int ypos = column * this->overworldTileset->tileHeight;
                if (layer.style[column][row] == "o")
                    overworldTileset->draw(layer.tiles[column][row], xpos, ypos);
                else if (layer.style[column][row] == "c")
                    caveTileset->draw(layer.tiles[column][row], xpos, ypos);
                else if (layer.style[column][row] == "i")
                    innerTileset->draw(layer.tiles[column][row], xpos, ypos);

            }
        }
    }
}


