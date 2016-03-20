//
// Created by mathbagu on 20/03/16.
//

#ifndef RICKDANGEROUS_RICKCONFIGURATION_HPP
#define RICKDANGEROUS_RICKCONFIGURATION_HPP

#include <string>

namespace zzbgames
{

namespace rick
{

class RickConfiguration
{
public:
    RickConfiguration();

    RickConfiguration(const RickConfiguration& config) = delete;

    ~RickConfiguration() = default;

    RickConfiguration& operator=(const RickConfiguration& config) = delete;

    unsigned int getWindowWidth() const;

    unsigned int getWindowHeight() const;

    void load(const std::string& filename);

    void save(const std::string& filename) const;

protected:
    unsigned int m_windowWidth;

    unsigned int m_windowHeight;

};

}

}

#endif //RICKDANGEROUS_RICKCONFIGURATION_HPP
