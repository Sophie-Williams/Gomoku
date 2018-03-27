//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_COMMANDUTILS_HPP
#define GOMOKU_COMMANDUTILS_HPP

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Commands.hpp"
#include "CommandStandardStream.hpp"

namespace gmk
{
    extern std::pair<Commands, std::string> cmd_str[];
    Commands getCommandFromString(std::string cmd_str);
    std::string commandToString(Commands cmd);
    std::vector<std::string> readBoardInputs(std::shared_ptr<ICommandInputStream> &stream);
    int *readTurnInput(const std::string &arg);
}

#endif //GOMOKU_COMMANDUTILS_HPP
