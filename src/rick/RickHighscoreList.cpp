//
// Created by mathbagu on 02/04/16.
//

#include <fstream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

#include <zzbgames/core/ExceptionBuilder.hpp>
#include <zzbgames/core/JSONUtils.hxx>
#include <zzbgames/rick/RickHighscoreList.hpp>

namespace zzbgames
{

namespace rick
{

RickHighscoreList::RickHighscoreList(unsigned long maxSize)
    : m_highscores(),
      m_maxSize(maxSize)
{
}

void RickHighscoreList::addDefaultHighscores()
{
    m_highscores.clear();
    m_highscores.insert(RickHighscore("NOBBY", 2000));
    m_highscores.insert(RickHighscore("RICKY", 2110));
    m_highscores.insert(RickHighscore("TELLY", 3000));
    m_highscores.insert(RickHighscore("ROB N BOB", 4000));
    m_highscores.insert(RickHighscore("KEN", 5000));
    m_highscores.insert(RickHighscore("DANGERSTU", 6000));
    m_highscores.insert(RickHighscore("JAYNE", 7000));
    m_highscores.insert(RickHighscore("SIMES", 8000));
}

void RickHighscoreList::addHighscore(const RickHighscore& highscore)
{
    if (m_highscores.size() == m_maxSize)
        m_highscores.erase(m_highscores.begin());
    m_highscores.insert(highscore);
}

std::set<RickHighscore>::const_reverse_iterator RickHighscoreList::begin()
{
    return m_highscores.crbegin();
}

std::set<RickHighscore>::const_reverse_iterator RickHighscoreList::end()
{
    return m_highscores.crend();
}

void RickHighscoreList::load(const std::string& filename)
{
    m_highscores.clear();

    std::ifstream stream(filename.c_str());
    if (!stream.good())
        throw ExceptionBuilder::iosFailureException("Failed to load highscores", filename);

    rapidjson::IStreamWrapper wrapper(stream);
    rapidjson::Document document;
    document.ParseStream(wrapper);

    if (document.HasMember("highscores") && document["highscores"].IsArray())
    {
        const auto& highscores = document["highscores"].GetArray();
        if (highscores.Size() == m_maxSize)
        {
            for (auto it = highscores.Begin(); it != highscores.End(); ++it)
            {
                if (it->IsObject())
                {
                    const auto& highscore = it->GetObject();
                    const std::string& name = JSONUtils::getMember<std::string>(highscore, "name");
                    const unsigned long& score = JSONUtils::getMember<unsigned long>(highscore, "score");

                    addHighscore(RickHighscore(name, score));
                }
            }
        }
    }

    if (m_highscores.size() != m_maxSize)
        throw ExceptionBuilder::iosFailureException("Failed to load highscores", filename);
}

void RickHighscoreList::save(const std::string& filename) const
{
    rapidjson::Document document(rapidjson::kObjectType);

    rapidjson::Value highscores(rapidjson::kArrayType);
    for (auto const& highscore : m_highscores)
    {
        rapidjson::Value highscoreJSON(rapidjson::kObjectType);
        JSONUtils::addMember(document, highscoreJSON, "name", highscore.getName());
        JSONUtils::addMember(document, highscoreJSON, "score", highscore.getScore());
        highscores.PushBack(highscoreJSON, document.GetAllocator());
    }

    JSONUtils::addMember(document, "highscores", highscores);

    std::ofstream stream(filename.c_str());
    if (!stream.good())
        throw ExceptionBuilder::iosFailureException("Failed to save highscores", filename);

    rapidjson::OStreamWrapper wrapper(stream);
    rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(wrapper);
    writer.SetIndent(' ', 2);
    document.Accept(writer);

    stream.close();
}

}

}