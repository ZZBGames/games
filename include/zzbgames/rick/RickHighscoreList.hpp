//
// Created by mathbagu on 02/04/16.
//

#ifndef RICKDANGEROUS_RICKHIGHSCORELIST_HPP
#define RICKDANGEROUS_RICKHIGHSCORELIST_HPP

#include <set>
#include <string>

#include <zzbgames/rick/RickHighscore.hpp>

namespace zzbgames
{

namespace rick
{

class RickHighscoreList
{
public:
    RickHighscoreList() = delete;

    RickHighscoreList(unsigned long maxSize);

    RickHighscoreList(const RickHighscoreList& highscoreList) = delete;

    ~RickHighscoreList() = default;

    RickHighscoreList& operator=(const RickHighscoreList& highscoreList) = delete;

    void addDefaultHighscores();

    void addHighscore(const RickHighscore& highscore);

    std::set<RickHighscore>::const_reverse_iterator begin();

    std::set<RickHighscore>::const_reverse_iterator end();

    void load(const std::string& filename);

    void save(const std::string& filename) const;

protected:
    std::set<RickHighscore> m_highscores;

    unsigned long m_maxSize;
};

}

}

#endif //RICKDANGEROUS_RICKHIGHSCORELIST_HPP
