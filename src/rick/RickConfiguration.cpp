//
// Created by mathbagu on 20/03/16.
//

#include <fstream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

#include <zzbgames/ExceptionBuilder.hpp>
#include <zzbgames/JSONUtils.hpp>
#include <zzbgames/rick/RickConfiguration.hpp>

namespace zzbgames
{

namespace rick
{

RickConfiguration::RickConfiguration()
    : m_windowWidth(320),
      m_windowHeight(200)
{
}

unsigned int RickConfiguration::getWindowHeight() const
{
    return m_windowHeight;
}

unsigned int RickConfiguration::getWindowWidth() const
{
    return m_windowWidth;
}

void RickConfiguration::load(const std::string& filename)
{
    std::ifstream stream(filename.c_str());
    if (!stream.good())
        throw ExceptionBuilder::iosFailureException("Failed to load configuration file", filename);

    rapidjson::IStreamWrapper wrapper(stream);
    rapidjson::Document document;
    document.ParseStream(wrapper);

    if (document.HasMember("window") && document["window"].IsObject())
    {
        const rapidjson::Value& window = document["window"].GetObject();
        m_windowWidth = JSONUtils::getMember(window, "width", m_windowWidth);
        m_windowHeight = JSONUtils::getMember(window, "height", m_windowHeight);
    }

    stream.close();
}

void RickConfiguration::save(const std::string& filename) const
{
    rapidjson::Document document(rapidjson::kObjectType);

    rapidjson::Value window(rapidjson::kObjectType);
    JSONUtils::addMember(document, window, "width", m_windowWidth);
    JSONUtils::addMember(document, window, "height", m_windowHeight);
    JSONUtils::addMember(document, "window", window);

    std::ofstream stream(filename.c_str());
    if (!stream.good())
        throw ExceptionBuilder::iosFailureException("Failed to save configuration file", filename);

    rapidjson::OStreamWrapper wrapper(stream);
    rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(wrapper);
    writer.SetIndent(' ', 2);
    document.Accept(writer);

    stream.close();
}

}

}