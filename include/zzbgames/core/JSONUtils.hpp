//
// Created by mathbagu on 03/04/16.
//

#ifndef ZZBGAMES_JSONUTILS_HPP
#define ZZBGAMES_JSONUTILS_HPP

#include <rapidjson/allocators.h>
#include <rapidjson/document.h>

namespace zzbgames
{

namespace JSONUtils
{

void addMember(rapidjson::Document& document, const std::string& name, rapidjson::Value& value);

template<typename T>
void addMember(rapidjson::Document& document, rapidjson::Value& object, const std::string& name, const T& value);

template<typename T>
T getMember(const rapidjson::Value& object, const std::string& name);

template<typename T>
T getMember(const rapidjson::Value& object, const std::string& name, const T& defaultValue);

}

}

#endif //ZZBGAMES_JSONUTILS_HPP
