//
// Created by Mathias on 27/11/2017.
//

#include <sstream>
#include <iterator>
#include "Commands/CommandManager.hpp"

namespace gmk
{
    CommandReader::CommandReader(const std::shared_ptr<ICommandInputStream> &in)
    : _in(in), _callback(nullptr) {}

    std::shared_ptr<ICommandInputStream> &CommandReader::getInputStream()
    {
        return (_in);
    }

    void CommandReader::readCommand()
    {
        if (_callback == nullptr)
            return;
        std::string line = _in->nextLine();
        std::istringstream iss(line);
        std::vector<std::string> args {
                std::istream_iterator<std::string>{iss},
                std::istream_iterator<std::string>{}
        };
        if (args.empty())
            return;
        Commands cmd = getCommandFromString(args[0]);
        _callback(cmd, args);
    }

    void CommandReader::setCallback(OnCommand callback)
    {
        _callback = callback;
    }
}