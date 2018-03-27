//
// Created by Mathias on 27/11/2017.
//

#include <iostream>
#include "Commands/CommandStandardStream.hpp"

namespace gmk
{
    std::string CommandStandardStream::nextLine()
    {
        std::string ret = "";
        std::getline (std::cin, ret);
        return (ret);
    }

    void CommandStandardStream::writeLine(const std::string &line)
    {
        std::cout << line << std::endl;
    }
}