//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_EXCEPTIONBUILDER_HPP
#define RICKDANGEROUS_EXCEPTIONBUILDER_HPP

#include <ios>
#include <stdexcept>
#include <string>

namespace zzbgames
{

class ExceptionBuilder
{
public:
    static std::ios_base::failure iosFailureException(const std::string& message, const std::string filename);

    static std::out_of_range outOfRangeException(const std::string& message, long value, long minValue, long maxValue);
};

}

#endif //RICKDANGEROUS_EXCEPTIONBUILDER_HPP
