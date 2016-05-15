//
// Created by mathbagu on 01/04/16.
//

#ifndef ZZBGAMES_EXCEPTIONBUILDER_HPP
#define ZZBGAMES_EXCEPTIONBUILDER_HPP

#include <ios>
#include <stdexcept>
#include <string>

namespace zzbgames
{

namespace ExceptionBuilder
{

template<typename T>
std::invalid_argument invalidArgumentException(const std::string& message, const T& value);

std::ios_base::failure iosFailureException(const std::string& message, const std::string filename);

template<typename T>
std::out_of_range outOfRangeException(const std::string& message, const T& value, const T& minValue, const T& maxValue);

}

}

#endif //ZZBGAMES_EXCEPTIONBUILDER_HPP
