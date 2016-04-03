//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RESOURCEMANAGER_HPP
#define RICKDANGEROUS_RESOURCEMANAGER_HPP

#include <ios>
#include <map>
#include <memory>
#include <string>

#include <zzbgames/ExceptionBuilder.hpp>

namespace zzbgames
{

template<typename ID, typename RESOURCE>
class ResourceManager
{
public:
    ResourceManager() = default;

    ResourceManager(const ResourceManager& resourceManager) = delete;

    ~ResourceManager() = default;

    ResourceManager& operator=(const ResourceManager& resourceManager) = delete;

    const RESOURCE& getResource(const ID& id) const;

    void load(const ID& id, const std::string& filename);

protected:
    std::map<ID, std::unique_ptr<RESOURCE> > m_resources;
};

template<typename ID, typename RESOURCE>
const RESOURCE& ResourceManager<ID, RESOURCE>::getResource(const ID& id) const
{
    auto resource = m_resources.find(id);
    if (resource == m_resources.end())
        throw ExceptionBuilder::invalidArgumentException("Unable to find resource");

    return *(resource->second);
}

template<typename ID, typename RESOURCE>
void ResourceManager<ID, RESOURCE>::load(const ID& id, const std::string& filename)
{
    std::unique_ptr<RESOURCE> resource(new RESOURCE());
    if (!resource->loadFromFile(filename))
        throw ExceptionBuilder::iosFailureException("Failed to load resource ", filename);

    m_resources.insert(std::make_pair(id, std::move(resource)));
}

}

#endif //RICKDANGEROUS_RESOURCEMANAGER_HPP
