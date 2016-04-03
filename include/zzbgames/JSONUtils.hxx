//
// Created by mathbagu on 03/04/16.
//

#ifndef RICKDANGEROUS_JSONUTILS_HXX
#define RICKDANGEROUS_JSONUTILS_HXX

#include <string>

#include <zzbgames/ExceptionBuilder.hpp>
#include <zzbgames/JSONUtils.hpp>

namespace zzbgames
{

namespace JSONUtils
{

void addMember(rapidjson::Document& document, const std::string& name, rapidjson::Value& value)
{
    rapidjson::Value jsonName(rapidjson::kStringType);
    jsonName.SetString(name.c_str(), static_cast<unsigned int>(name.size()), document.GetAllocator());

    document.AddMember(jsonName, value, document.GetAllocator());
}

template<typename T>
void addMember(rapidjson::Document& document, rapidjson::Value& object, const std::string& name, const T& value)
{
    rapidjson::Value jsonName(rapidjson::kStringType);
    jsonName.SetString(name.c_str(), static_cast<unsigned int>(name.size()), document.GetAllocator());

    object.AddMember(jsonName, value, document.GetAllocator());
}

template<>
void addMember(rapidjson::Document& document, rapidjson::Value& object, const std::string& name,
               const std::string& value)
{
    rapidjson::Value jsonName(rapidjson::kStringType);
    jsonName.SetString(name.c_str(), static_cast<unsigned int>(name.size()), document.GetAllocator());

    rapidjson::Value jsonValue(rapidjson::kStringType);
    jsonValue.SetString(value.c_str(), static_cast<unsigned int>(value.size()), document.GetAllocator());

    object.AddMember(jsonName, jsonValue, document.GetAllocator());
}

template<>
unsigned int getMember(const rapidjson::Value& object, const std::string& name)
{
    if ((!object.HasMember(name.c_str())) || (!object[name.c_str()].IsUint()))
        throw ExceptionBuilder::invalidArgumentException("Unable to find attribute", name);

    return object[name.c_str()].GetUint();
}

template<>
unsigned long getMember(const rapidjson::Value& object, const std::string& name)
{
    if ((!object.HasMember(name.c_str())) || (!object[name.c_str()].IsUint64()))
        throw ExceptionBuilder::invalidArgumentException("Unable to find attribute", name);

    return object[name.c_str()].GetUint64();
}

template<>
std::string getMember(const rapidjson::Value& object, const std::string& name)
{
    if ((!object.HasMember(name.c_str())) || (!object[name.c_str()].IsString()))
        throw ExceptionBuilder::invalidArgumentException("Unable to find attribute", name);

    return object[name.c_str()].GetString();
}


template<typename T>
T getMember(const rapidjson::Value& object, const std::string& name, const T& defaultValue)
{
    T value = defaultValue;
    try
    {
        value = getMember<T>(object, name);
    }
    catch (const std::invalid_argument& exc)
    { }

    return value;
}

}

// Template instantiation
namespace JSONUtils
{

template void addMember(rapidjson::Document& document, rapidjson::Value& object, const std::string& name,
                        const unsigned int& value);

template unsigned int getMember(const rapidjson::Value& object, const std::string& name,
                                const unsigned int& defaultValue);

template unsigned long getMember(const rapidjson::Value& object, const std::string& name,
                                 const unsigned long& defaultValue);

}

}

#endif //RICKDANGEROUS_JSONUTILS_HXX