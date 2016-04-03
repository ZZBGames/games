//
// Created by mathbagu on 02/04/16.
//

#include <zzbgames/rick/RickHighscore.hpp>

namespace zzbgames
{

namespace rick
{

RickHighscore::RickHighscore(const std::string& name, unsigned long score)
    : m_name(name),
      m_score(score)
{
}

bool RickHighscore::operator<(const RickHighscore& highscore) const
{
    return m_score < highscore.m_score;
}

const std::string& RickHighscore::getName() const
{
    return m_name;
}

unsigned long RickHighscore::getScore() const
{
    return m_score;
}

}

}