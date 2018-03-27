//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_ICOMMANDOUTPUTSTREAM_HPP
#define GOMOKU_ICOMMANDOUTPUTSTREAM_HPP

#include <string>

namespace gmk
{
    /**
     * Represent output where commands are written
     */
    class ICommandOutputStream
    {
    public:
        ICommandOutputStream() = default;
        ICommandOutputStream(const ICommandOutputStream&) = default;
        ICommandOutputStream &operator=(const ICommandOutputStream&) = default;
        virtual ~ICommandOutputStream() = default;

    public:
        // Write the line on the output
        virtual void writeLine(const std::string &line) = 0;
    };
}

#endif //GOMOKU_ICOMMANDOUTPUTSTREAM_HPP
