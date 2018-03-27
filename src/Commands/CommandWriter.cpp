//
// Created by Mathias on 28/11/2017.
//

#include <algorithm>
#include "Commands/CommandManager.hpp"

namespace gmk
{
    void CommandWriter::sendLine(const std::string &line)
    {
        std::for_each(_out.begin(), _out.end(), [&line](const std::shared_ptr<ICommandOutputStream> &out) {
            out->writeLine(line);
        });
    }

    void CommandWriter::sendCommand(const Commands cmd, const std::string args)
    {
        std::string send = commandToString(cmd);
        if (!args.empty())
            send += " " + args;
        sendLine(send);
    }

    void CommandWriter::sendCommand(const Commands cmd, const std::vector<std::string> &args)
    {
        std::string send = commandToString(cmd);
        for (std::string ar : args)
            send += " " + ar;
        sendLine(send);
    }

    void CommandWriter::sendPlayCommand(int a, int b)
    {
        std::string send = std::to_string(a) + "," + std::to_string(b);
        sendLine(send);
    }

    void CommandWriter::addOutputStream(const std::shared_ptr<ICommandOutputStream> &stream)
    {
        _out.push_back(stream);
    }
}