//
// Created by Mathias on 27/11/2017.
//

#ifndef GOMOKU_COMMANDMANAGER_HPP
#define GOMOKU_COMMANDMANAGER_HPP

#include "CommandWriter.hpp"
#include "CommandReader.hpp"
#include "CommandUtils.hpp"

namespace gmk
{
    class CommandManager
    {
    private:
        std::shared_ptr<CommandWriter> _writer = nullptr;
        std::shared_ptr<CommandReader> _reader = nullptr;
        std::vector<std::pair<Commands, OnCommand>> _handlers;

    public:
        CommandManager();
        CommandManager(const std::shared_ptr<ICommandInputStream> &in, const std::shared_ptr<ICommandOutputStream> &out);
        CommandManager(const CommandManager&) = default;
        CommandManager &operator=(const CommandManager&) = default;
        virtual ~CommandManager() = default;

    private:
        void commandCallback(const Commands cmd, const std::vector<std::string> args);

    public:
        // Trigger command read
        void readNextCommand();
        // Set the command handler for this command
        void setCommandHandler(Commands cmd, OnCommand handler);
        // Get the writer
        std::shared_ptr<CommandWriter> getWriter();
        // Get the reader
        std::shared_ptr<CommandReader> getReader();
    };
}

#endif //GOMOKU_COMMANDMANAGER_HPP
