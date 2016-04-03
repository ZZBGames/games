//
// Created by mathbagu on 02/04/16.
//

#ifndef RICKDANGEROUS_RICKHIGHSCORE_HPP
#define RICKDANGEROUS_RICKHIGHSCORE_HPP

#include <string>

namespace zzbgames
{

namespace rick
{

class RickHighscore
{
public:
    RickHighscore(const std::string& name, unsigned long score);

    RickHighscore(const RickHighscore& highscore) = default;

    ~RickHighscore() = default;

    RickHighscore& operator=(const RickHighscore& highscore) = default;

    bool operator<(const RickHighscore& highscore) const;

    const std::string& getName() const;

    unsigned long getScore() const;

protected:
    RickHighscore() = default;

    std::string m_name;

    unsigned long m_score;
};

}

}

#endif //RICKDANGEROUS_RICKHIGHSCORE_HPP
