//
// Created by Mathias on 27/11/2017.
//

#ifndef GOMOKU_COMMANDSTANDARDSTREAM_HPP
#define GOMOKU_COMMANDSTANDARDSTREAM_HPP

#include "ICommandInputStream.hpp"
#include "ICommandOutputStream.hpp"

namespace gmk
{
    /**
    * Represent the standard input and output stream
    */
    class CommandStandardStream : public ICommandInputStream, public ICommandOutputStream
    {
    public:
        CommandStandardStream() = default;
        CommandStandardStream(const CommandStandardStream&) = default;
        CommandStandardStream &operator=(const CommandStandardStream&) = default;
        virtual ~CommandStandardStream() = default;

    public:
        std::string nextLine();
        void writeLine(const std::string &line);
    };
}

#endif //GOMOKU_COMMANDSTANDARDSTREAM_HPP
