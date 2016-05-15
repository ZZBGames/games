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

void usage(int /*argc*/, char** argv)
{
    std::cerr << "Usage: " << argv[0] << " <source> <destination>" << std::endl
    << std::endl
    << "Required arguments:" << std::endl
    << "  -s | --src-tileset:" << std::endl
    << "    The source file name." << std::endl
    << "  -d | --dest-tileset:" << std::endl
    << "    The destination file name." << std::endl
    << std::endl
    << "Optional arguments:" << std::endl
    << "  -h | --help:" << std::endl
    << "    Display this help." << std::endl
    << std::endl
    << "  --dest-margin-top:" << std::endl
    << "    The top margin of the destination tileset in pixels." << std::endl
    << "  --dest-margin-left:" << std::endl
    << "    The top margin of the destination tileset in pixels." << std::endl
    << "  --dest-margin-bottom:" << std::endl
    << "    The bottom margin of the destination tileset in pixels." << std::endl
    << "  --dest-margin-right:" << std::endl
    << "    The right margin of the destination tileset in pixels." << std::endl
    << std::endl
    << "  --dest-spacing-top:" << std::endl
    << "    The top spacing of each tile in the destination tileset in pixels." << std::endl
    << "  --dest-spacing-left:" << std::endl
    << "    The top spacing of each tile in the destination tileset in pixels." << std::endl
    << "  --dest-spacing-bottom:" << std::endl
    << "    The bottom spacing of each in the destination tileset tile in pixels." << std::endl
    << "  --dest-spacing-right:" << std::endl
    << "    The right spacing of each in the destination tileset tile in pixels." << std::endl
    << std::endl
    << "  --src-margin-top:" << std::endl
    << "    The top margin of the source tileset in pixels." << std::endl
    << "  --src-margin-left:" << std::endl
    << "    The top margin of the source tileset in pixels." << std::endl
    << "  --src-margin-bottom:" << std::endl
    << "    The bottom margin of the source tileset in pixels." << std::endl
    << "  --src-margin-right:" << std::endl
    << "    The right margin of the source tileset in pixels." << std::endl
    << std::endl
    << "  --src-spacing-top:" << std::endl
    << "    The top spacing of each tile in the source tileset in pixels." << std::endl
    << "  --src-spacing-left:" << std::endl
    << "    The top spacing of each tile in the source tileset in pixels." << std::endl
    << "  --src-spacing-bottom:" << std::endl
    << "    The bottom spacing of each in the source tileset tile in pixels." << std::endl
    << "  --src-spacing-right:" << std::endl
    << "    The right spacing of each in the source tileset tile in pixels." << std::endl
    << std::endl
    << "  --tile-width:" << std::endl
    << "    The width of each tile in pixels." << std::endl
    << "  --tile-height:" << std::endl
    << "    The width of each tile in pixels." << std::endl
    << std::endl;
}

enum OPTION
{
    TILE_WIDTH,
    TILE_HEIGHT,
    SRC_TILESET,
    SRC_MARGIN_TOP,
    SRC_MARGIN_LEFT,
    SRC_MARGIN_BOTTOM,
    SRC_MARGIN_RIGHT,
    SRC_SPACING_TOP,
    SRC_SPACING_LEFT,
    SRC_SPACING_BOTTOM,
    SRC_SPACING_RIGHT,
    DEST_TILESET,
    DEST_MARGIN_TOP,
    DEST_MARGIN_LEFT,
    DEST_MARGIN_BOTTOM,
    DEST_MARGIN_RIGHT,
    DEST_SPACING_TOP,
    DEST_SPACING_LEFT,
    DEST_SPACING_BOTTOM,
    DEST_SPACING_RIGHT,
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
        {"tile-width",          required_argument, 0, TILE_WIDTH},
        {"tile-height",         required_argument, 0, TILE_HEIGHT},
        {"src-tileset",         required_argument, 0, SRC_TILESET},
        {"src-margin-top",      required_argument, 0, SRC_MARGIN_TOP},
        {"src-margin-left",     required_argument, 0, SRC_MARGIN_LEFT},
        {"src-margin-bottom",   required_argument, 0, SRC_MARGIN_BOTTOM},
        {"src-margin-right",    required_argument, 0, SRC_MARGIN_RIGHT},
        {"src-spacing-top",     required_argument, 0, SRC_SPACING_TOP},
        {"src-spacing-left",    required_argument, 0, SRC_SPACING_LEFT},
        {"src-spacing-bottom",  required_argument, 0, SRC_SPACING_BOTTOM},
        {"src-spacing-right",   required_argument, 0, SRC_SPACING_RIGHT},
        {"dest-tileset",        required_argument, 0, DEST_TILESET},
        {"dest-margin-top",     required_argument, 0, DEST_MARGIN_TOP},
        {"dest-margin-left",    required_argument, 0, DEST_MARGIN_LEFT},
        {"dest-margin-bottom",  required_argument, 0, DEST_MARGIN_BOTTOM},
        {"dest-margin-right",   required_argument, 0, DEST_MARGIN_RIGHT},
        {"dest-spacing-top",    required_argument, 0, DEST_SPACING_TOP},
        {"dest-spacing-left",   required_argument, 0, DEST_SPACING_LEFT},
        {"dest-spacing-bottom", required_argument, 0, DEST_SPACING_BOTTOM},
        {"dest-spacing-right",  required_argument, 0, DEST_SPACING_RIGHT},
        {"help",                no_argument,       0, HELP},
        {0, 0,                                     0, 0}
    };

    int returnCode = 0;

    try
    {
        zzbgames::Dimension tileSize;

        std::string srcTilesetName;
        zzbgames::Insets srcMargin;
        zzbgames::Insets srcSpacing;

        std::string destTilesetName;
        zzbgames::Insets destMargin;
        zzbgames::Insets destSpacing;

        int option_index = 0;
        int missingRequiredOptions = 2;
        int c = getopt_long(argc, argv, "hs:d:", options, &option_index);
        while (c != -1)
        {
            switch (c)
            {
                case TILE_WIDTH:
                    tileSize.setWidth(std::stoi(optarg));
                    break;

                case TILE_HEIGHT:
                    tileSize.setHeight(std::stoi(optarg));
                    break;

                case SRC_TILESET:
                case 's':
                    srcTilesetName = optarg;
                    missingRequiredOptions--;
                    break;

                case SRC_MARGIN_TOP:
                    srcMargin.setTop(std::atoi(optarg));
                    break;

                case SRC_MARGIN_LEFT:
                    srcMargin.setLeft(std::atoi(optarg));
                    break;

                case SRC_MARGIN_BOTTOM:
                    srcMargin.setBottom(std::atoi(optarg));
                    break;

                case SRC_MARGIN_RIGHT:
                    srcMargin.setRight(std::atoi(optarg));
                    break;

                case SRC_SPACING_TOP:
                    srcSpacing.setTop(std::atoi(optarg));
                    break;

                case SRC_SPACING_LEFT:
                    srcSpacing.setLeft(std::atoi(optarg));
                    break;

                case SRC_SPACING_BOTTOM:
                    srcSpacing.setBottom(std::atoi(optarg));
                    break;

                case SRC_SPACING_RIGHT:
                    srcSpacing.setRight(std::atoi(optarg));
                    break;

                case DEST_TILESET:
                case 'd':
                    destTilesetName = optarg;
                    missingRequiredOptions--;
                    break;

                case DEST_MARGIN_TOP:
                    destMargin.setTop(std::atoi(optarg));
                    break;

                case DEST_MARGIN_LEFT:
                    destMargin.setLeft(std::atoi(optarg));
                    break;

                case DEST_MARGIN_BOTTOM:
                    destMargin.setBottom(std::atoi(optarg));
                    break;

                case DEST_MARGIN_RIGHT:
                    destMargin.setRight(std::atoi(optarg));
                    break;

                case DEST_SPACING_TOP:
                    destSpacing.setTop(std::atoi(optarg));
                    break;

                case DEST_SPACING_LEFT:
                    destSpacing.setLeft(std::atoi(optarg));
                    break;

                case DEST_SPACING_BOTTOM:
                    destSpacing.setBottom(std::atoi(optarg));
                    break;

                case DEST_SPACING_RIGHT:
                    destSpacing.setRight(std::atoi(optarg));
                    break;

                case HELP:
                case 'h':
                    throw UsageError();
            }

            c = getopt_long(argc, argv, "hs:d:", options, &option_index);
        }

        if (missingRequiredOptions != 0)
            throw UsageError();

        // Load the source tileset
        zzbgames::Tileset srcTileset(srcTilesetName, tileSize, srcMargin, srcSpacing);
        const sf::Image& srcImage = srcTileset.getImage();

        // Create the destination tileset in memory
        sf::Image destImage;
        unsigned int destTileWidth = tileSize.getWidth() + destSpacing.getLeft() + destSpacing.getRight();
        unsigned int destTileHeight = tileSize.getHeight() + destSpacing.getTop() + destSpacing.getBottom();
        unsigned int destWidth =
            srcTileset.getColumnCount() * destTileWidth + destMargin.getLeft() + destMargin.getRight();
        unsigned int destHeight =
            srcTileset.getRowCount() * destTileHeight + destMargin.getTop() + destMargin.getBottom();
        destImage.create(destWidth, destHeight);

        // Copy each tile from source tileset to destination tileset
        for (unsigned long rowIndex = 0; rowIndex < srcTileset.getRowCount(); ++rowIndex)
        {
            for (unsigned long columnIndex = 0; columnIndex < srcTileset.getColumnCount(); ++columnIndex)
            {
                const sf::IntRect& rect = srcTileset.getTileAsRect(
                    rowIndex * srcTileset.getColumnCount() + columnIndex);

                unsigned int destX = destMargin.getLeft() + columnIndex * destTileWidth;
                unsigned int destY = destMargin.getTop() + rowIndex * destTileHeight;

                destImage.copy(srcImage, destX, destY, rect);
            }
        }

        destImage.saveToFile(destTilesetName);
    }
    catch (UsageError& exc)
    {
        usage(argc, argv);
        returnCode = 1;
    }


    return returnCode;
}