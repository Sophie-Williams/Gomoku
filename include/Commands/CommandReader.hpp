//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_COMMANDREADER_HPP
#define GOMOKU_COMMANDREADER_HPP

#include <functional>
#include <vector>
#include <memory>
#include "Commands.hpp"
#include "CommandStandardStream.hpp"

namespace gmk
{
    // Used by the command reader to call back when a command is received
    // The parameter are the command and a vector of command arguments
    using OnCommand = std::function<void(const gmk::Commands, const std::vector<std::string>)>;

    /**
     * Read commands from input in a thread, compute it and callback the command manager
     */
    class CommandReader
    {
    private:
        std::shared_ptr<ICommandInputStream> _in = nullptr;
        OnCommand _callback = nullptr;

    public:
        CommandReader() = default;
        CommandReader(const std::shared_ptr<ICommandInputStream> &in);
        CommandReader(const CommandReader&) = default;
        CommandReader &operator=(const CommandReader&) = default;
        virtual ~CommandReader() = default;

    public:
        // Manually read the next command
        virtual void readCommand();
        // Set the command callback
        virtual void setCallback(OnCommand callback);
        // Get the input stream shared_ptr
        virtual std::shared_ptr<ICommandInputStream> &getInputStream();
    };
}

#endif //GOMOKU_COMMANDREADER_HPP
