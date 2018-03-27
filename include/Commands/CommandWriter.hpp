//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_COMMANDWRITER_HPP
#define GOMOKU_COMMANDWRITER_HPP

#include <memory>
#include <string>
#include <vector>
#include "Commands.hpp"
#include "CommandStandardStream.hpp"

namespace gmk
{
    /**
     * Write commands to output
     */
    class CommandWriter
    {
    private:
        std::vector<std::shared_ptr<ICommandOutputStream>> _out;

    private:
        void sendLine(const std::string &line);

    public:
        CommandWriter() = default;
        CommandWriter(const CommandWriter&) = default;
        CommandWriter &operator=(const CommandWriter&) = default;
        virtual ~CommandWriter() = default;

    public:
        // Send the command, args are appended to a one line cmd string
        virtual void sendCommand(const Commands cmd, const std::vector<std::string> &args);
        // Send the command, args are appended to a one line cmd string
        virtual void sendCommand(const Commands cmd, const std::string args = "");
        // Send the play command (wich consist of only a,b)
        virtual void sendPlayCommand(int a, int b);
        // Add a OutputStream
        virtual void addOutputStream(const std::shared_ptr<ICommandOutputStream> &stream);
    };
}

#endif //GOMOKU_COMMANDWRITER_HPP
