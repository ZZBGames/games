//
// Created by mathbagu on 12/03/16.
//

#include <iostream>
#include <stdexcept>

#include <zzbgames/rick/RickApplication.hpp>

int main()
{
    int exitCode = 0;

    try
    {
        zzbgames::rick::RickApplication app;
        exitCode = app.run();
    }
    catch (std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        exitCode = 1;
    }

    return exitCode;
}