//
// Created by Mathias on 28/11/2017.
//

#include "Commands/CommandManager.hpp"

namespace gmk
{
    std::pair<Commands, std::string> cmd_str[] =
    {
        {START, "START"},
        {END, "END"},
        {OK, "OK"},
        {TURN, "TURN"},
        {BEGIN, "BEGIN"},
        {BOARD, "BOARD"},
        {INFO, "INFO"},
        {ABOUT, "ABOUT"},
        {UNKNOWN, "UNKNOWN"},
        {ERROR_CMD, "ERROR"},
        {MESSAGE, "MESSAGE"},
        {DEBUG_CMD, "DEBUG"}
    };

    Commands getCommandFromString(std::string cmd)
    {
        for (std::pair<Commands, std::string> pair : cmd_str)
        {
            if (pair.second == cmd)
                return (pair.first);
        }
        return (UNKNOWN);
    }

    std::string commandToString(Commands cmd)
    {
        for (std::pair<Commands, std::string> pair : cmd_str)
        {
            if (pair.first == cmd)
                return (pair.second);
        }
        return ("UNKNOWN");
    }

    std::vector<std::string> readBoardInputs(std::shared_ptr<ICommandInputStream> &stream)
    {
        std::vector<std::string> ret;
        std::string line;

        while ((line = stream->nextLine()) != "DONE")
            ret.push_back(line);
        return (ret);
    }

    int *readTurnInput(const std::string &arg)
    {
        auto *ret = new int[2]
                {
                        std::stoi(arg.substr(0, arg.find(','))),
                        std::stoi(arg.substr(arg.find(',') + 1))
                };
        return (ret);
    }
}