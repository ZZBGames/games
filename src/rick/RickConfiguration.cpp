//
// Created by mathbagu on 20/03/16.
//

#include <fstream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

#include <zzbgames/ExceptionBuilder.hpp>
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
        if (window.HasMember("width") && window["width"].IsUint())
            m_windowWidth = window["width"].GetUint();
        if (window.HasMember("height") && window["height"].IsUint())
            m_windowHeight = window["height"].GetUint();
    }

    stream.close();
}

void RickConfiguration::save(const std::string& filename) const
{
    rapidjson::Document document(rapidjson::kObjectType);

    rapidjson::Value window(rapidjson::kObjectType);
    window.AddMember("width", m_windowWidth, document.GetAllocator());
    window.AddMember("height", m_windowHeight, document.GetAllocator());
    document.AddMember("window", window, document.GetAllocator());

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