//
// Created by mathbagu on 02/04/16.
//

#ifndef RICKDANGEROUS_RICKTEXTBUILDER_HPP
#define RICKDANGEROUS_RICKTEXTBUILDER_HPP

#include <memory>
#include <string>

#include <zzbgames/rick/RickText.hpp>
#include <zzbgames/rick/RickTileset.hpp>

namespace zzbgames
{

namespace rick
{

class RickTextBuilder
{
public:
    enum class Alignment
    {
        LEFT,
        RIGHT
    };

public:
    RickTextBuilder(const RickTileset& tileset);

    RickTextBuilder(const RickTextBuilder& builder) = default;

    ~RickTextBuilder() = default;

    RickTextBuilder& operator=(const RickTextBuilder& builder) = default;

    std::unique_ptr<RickText> build() const;

    RickTextBuilder& setAlignment(const Alignment& alignment);

    RickTextBuilder& setFillCharacter(const char character);

    RickTextBuilder& setLength(unsigned long length);

    RickTextBuilder& setText(const std::string& text);

protected:
    const RickTileset& m_tileset;

    Alignment m_alignment;

    char m_fillCharacter;

    unsigned long m_length;

    std::string m_text;
};

}

}

#endif //RICKDANGEROUS_RICKTEXTBUILDER_HPP
