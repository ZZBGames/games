//
// Created by mathbagu on 15/05/16.
//

#include <iostream>
#include <stdexcept>
#include <vector>

#include <getopt.h>

#include <SFML/Graphics/Image.hpp>

#include <zzbgames/core/Dimension.hpp>
#include <zzbgames/core/Insets.hpp>
#include <zzbgames/core/Tileset.hpp>

#include "TileMapper.hpp"

void usage(int /*argc*/, char** argv)
{
    std::cerr << "Usage: " << argv[0] << " <tileset> <map>" << std::endl
    << std::endl
    << "Required arguments:" << std::endl
    << "  -t | --tileset:" << std::endl << "    The tileset file name." << std::endl
    << "  -m | --map:" << std::endl << "    The map file name." << std::endl
    << std::endl
    << "Optional arguments:" << std::endl
    << "  -h | --help:" << std::endl << "    Display this help." << std::endl
    << std::endl
    << "  --margin-top:" << std::endl << "    The top margin of the tileset in pixels." << std::endl
    << "  --margin-left:" << std::endl << "    The top margin of the tileset in pixels." << std::endl
    << "  --margin-bottom:" << std::endl << "    The bottom margin of the tileset in pixels." << std::endl
    << "  --margin-right:" << std::endl << "    The right margin of the tileset in pixels." << std::endl
    << std::endl
    << "  --spacing-top:" << std::endl << "    The top spacing of each tile in pixels." << std::endl
    << "  --spacing-left:" << std::endl << "    The top spacing of each tile in pixels." << std::endl
    << "  --spacing-bottom:" << std::endl << "    The bottom spacing of each tile in pixels." << std::endl
    << "  --spacing-right:" << std::endl << "    The right spacing of each tile in pixels." << std::endl
    << std::endl
    << "  --tile-width:" << std::endl << "    The width of each tile in pixels." << std::endl
    << "  --tile-height:" << std::endl << "    The width of each tile in pixels." << std::endl
    << std::endl;
}

enum OPTION
{
    TILESET,
    TILE_WIDTH,
    TILE_HEIGHT,
    MARGIN_TOP,
    MARGIN_LEFT,
    MARGIN_BOTTOM,
    MARGIN_RIGHT,
    SPACING_TOP,
    SPACING_LEFT,
    SPACING_BOTTOM,
    SPACING_RIGHT,
    MAP,
    HELP
};

class UsageError : public std::runtime_error
{
public:
    UsageError() : std::runtime_error("usage")
    { }
};

int main(int argc, char** argv)
{
    static struct option options[] = {
        {"tileset",        required_argument, 0, TILESET},
        {"tile-width",     required_argument, 0, TILE_WIDTH},
        {"tile-height",    required_argument, 0, TILE_HEIGHT},
        {"margin-top",     required_argument, 0, MARGIN_TOP},
        {"margin-left",    required_argument, 0, MARGIN_LEFT},
        {"margin-bottom",  required_argument, 0, MARGIN_BOTTOM},
        {"margin-right",   required_argument, 0, MARGIN_RIGHT},
        {"spacing-top",    required_argument, 0, SPACING_TOP},
        {"spacing-left",   required_argument, 0, SPACING_LEFT},
        {"spacing-bottom", required_argument, 0, SPACING_BOTTOM},
        {"spacing-right",  required_argument, 0, SPACING_RIGHT},
        {"map",            required_argument, 0, MAP},
        {"help",           no_argument,       0, HELP},
        {0, 0,                                0, 0}
    };

    int returnCode = 0;

    try
    {
        std::string tilesetName;
        zzbgames::Dimension tileSize;
        zzbgames::Insets margin;
        zzbgames::Insets spacing;

        std::string mapName;

        int option_index = 0;
        int missingRequiredOptions = 2;
        int c = getopt_long(argc, argv, "ht:m:", options, &option_index);
        while (c != -1)
        {
            switch (c)
            {
                case TILESET:
                case 't':
                    tilesetName = optarg;
                    missingRequiredOptions--;
                    break;

                case TILE_WIDTH:
                    tileSize.setWidth(std::stoi(optarg));
                    break;

                case TILE_HEIGHT:
                    tileSize.setHeight(std::stoi(optarg));
                    break;

                case MARGIN_TOP:
                    margin.setTop(std::atoi(optarg));
                    break;

                case MARGIN_LEFT:
                    margin.setLeft(std::atoi(optarg));
                    break;

                case MARGIN_BOTTOM:
                    margin.setBottom(std::atoi(optarg));
                    break;

                case MARGIN_RIGHT:
                    margin.setRight(std::atoi(optarg));
                    break;

                case SPACING_TOP:
                    spacing.setTop(std::atoi(optarg));
                    break;

                case SPACING_LEFT:
                    spacing.setLeft(std::atoi(optarg));
                    break;

                case SPACING_BOTTOM:
                    spacing.setBottom(std::atoi(optarg));
                    break;

                case SPACING_RIGHT:
                    spacing.setRight(std::atoi(optarg));
                    break;

                case MAP:
                case 'm':
                    mapName = optarg;
                    missingRequiredOptions--;
                    break;

                case HELP:
                case 'h':
                    throw UsageError();
            }

            c = getopt_long(argc, argv, "ht:m:", options, &option_index);
        }

        if (missingRequiredOptions != 0)
            throw UsageError();

        // Load the tileset
        zzbgames::Tileset tileset(tilesetName, tileSize, margin, spacing);

        // Load the map
        sf::Image map;
        map.loadFromFile(mapName);

        zzbgames::mapper::TileMapper tileMapper(tileset);
        const std::vector<unsigned long>& indexes = tileMapper.getTileIndexes(map);
        for (const auto& index : indexes)
            std::cout << index << ";";
        std::cout << std::endl;
    }
    catch (UsageError& exc)
    {
        usage(argc, argv);
        returnCode = 1;
    }


    return returnCode;
}