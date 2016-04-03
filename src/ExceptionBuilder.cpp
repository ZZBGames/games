//
// Created by mathbagu on 01/04/16.
//

#include <sstream>

#include <zzbgames/ExceptionBuilder.hpp>

namespace zzbgames
{

std::invalid_argument ExceptionBuilder::invalidArgumentException(const std::string& message)
{
    return std::invalid_argument(message);
}

std::ios_base::failure ExceptionBuilder::iosFailureException(const std::string& message, const std::string filename)
{
    std::ostringstream oss;
    oss << message << ": " << filename;

    return std::ios_base::failure(oss.str());
}

std::out_of_range ExceptionBuilder::outOfRangeException(const std::string& message, long value, long minValue,
                                                        long maxValue)
{
    std::ostringstream oss;
    oss << message << " [" << minValue << ", " << (maxValue - 1) << "] (value = " << value << ")";

    return std::out_of_range(oss.str());
}

}