//
// Created by mathbagu on 01/04/16.
//

#ifndef ZZBGAMES_EXCEPTIONBUILDER_HXX
#define ZZBGAMES_EXCEPTIONBUILDER_HXX

#include <sstream>

#include <zzbgames/core/ExceptionBuilder.hpp>

namespace zzbgames
{

namespace ExceptionBuilder
{

template<typename T>
std::invalid_argument invalidArgumentException(const std::string& message, const T& value)
{
    std::ostringstream oss;
    oss << message << ": " << value;

    return std::invalid_argument(oss.str());
}

std::ios_base::failure iosFailureException(const std::string& message, const std::string filename)
{
    std::ostringstream oss;
    oss << message << ": " << filename;

    return std::ios_base::failure(oss.str());
}

template<typename T>
std::out_of_range outOfRangeException(const std::string& message, const T& value, const T& minValue, const T& maxValue)
{
    std::ostringstream oss;
    oss << message << " [" << minValue << ", " << (maxValue - 1) << "] (value = " << value << ")";

    return std::out_of_range(oss.str());
}

}

// Template instantiation
namespace ExceptionBuilder
{

template std::invalid_argument invalidArgumentException(const std::string& message, const std::string& value);

template std::out_of_range outOfRangeException(const std::string& message, const unsigned long& value,
                                               const unsigned long& minValue, const unsigned long& maxValue);

}

}

#endif //ZZBGAMES_EXCEPTIONBUILDER_HXX