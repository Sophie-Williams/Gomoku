//
// Created by Mathias on 28/11/2017.
//

#include <algorithm>
#include "Commands/CommandManager.hpp"

namespace gmk
{
    CommandManager::CommandManager()
    {
        std::shared_ptr<CommandStandardStream> standard = std::make_shared<CommandStandardStream>();
        _writer = std::make_shared<CommandWriter>();
        _writer->addOutputStream(standard);
        _reader = std::make_shared<CommandReader>(standard);
        _reader->setCallback(std::bind(&CommandManager::commandCallback, this,
                                       std::placeholders::_1, std::placeholders::_2));
    }

    CommandManager::CommandManager(const std::shared_ptr<ICommandInputStream> &in,
                                   const std::shared_ptr<ICommandOutputStream> &out)
    {
        _writer = std::make_shared<CommandWriter>();
        _writer->addOutputStream(out);
        _reader = std::make_shared<CommandReader>(CommandReader(in));
        _reader->setCallback(std::bind(&CommandManager::commandCallback, this,
                                       std::placeholders::_1, std::placeholders::_2));
    }

    void CommandManager::commandCallback(const Commands cmd, const std::vector<std::string> args)
    {
        std::for_each(_handlers.begin(), _handlers.end(), [&cmd, &args](const std::pair<Commands, OnCommand> h)
        {
            if (h.first == cmd)
                h.second(cmd, args);
        });
    }

    std::shared_ptr<CommandWriter> CommandManager::getWriter()
    {
        return (_writer);
    }

    void CommandManager::readNextCommand()
    {
        _reader->readCommand();
    }

    void CommandManager::setCommandHandler(Commands cmd, OnCommand handler)
    {
        _handlers.push_back({cmd, handler});
    }

    std::shared_ptr<CommandReader> CommandManager::getReader()
    {
        return (_reader);
    }
}