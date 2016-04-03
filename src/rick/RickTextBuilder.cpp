//
// Created by mathbagu on 02/04/16.
//

#include <zzbgames/rick/RickTextBuilder.hpp>

namespace zzbgames
{

namespace rick
{

RickTextBuilder::RickTextBuilder(const RickTileset& tileset)
    : m_tileset(tileset),
      m_alignment(Alignment::LEFT),
      m_length(std::numeric_limits<unsigned long>::max()),
      m_text()
{
}

std::unique_ptr<RickText> RickTextBuilder::build() const
{
    std::string buffer(m_length, m_fillCharacter);
    if (m_text.size() >= m_length)
    {
        buffer.replace(0, m_length, m_text, 0, m_length);
    }
    else
    {
        if (m_alignment == Alignment::LEFT)
            buffer.replace(0, m_text.size(), m_text);
        else
            buffer.replace(m_length - m_text.size(), m_text.size(), m_text);
    }

    return std::move(std::unique_ptr<RickText>(new RickText(buffer, m_tileset)));
}

RickTextBuilder& RickTextBuilder::setAlignment(const Alignment& alignment)
{
    m_alignment = alignment;

    return *this;
}

RickTextBuilder& RickTextBuilder::setFillCharacter(const char character)
{
    m_fillCharacter = character;

    return *this;
}

RickTextBuilder& RickTextBuilder::setLength(unsigned long length)
{
    m_length = length;

    return *this;
}

RickTextBuilder& RickTextBuilder::setText(const std::string& text)
{
    m_text = text;

    return *this;
}

}

}