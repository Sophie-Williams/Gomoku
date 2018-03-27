//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_ICOMMANDINPUTSTREAM_HPP
#define GOMOKU_ICOMMANDINPUTSTREAM_HPP

#include <string>

namespace gmk
{
    /**
     * Represent the input commands are read from
     */
    class ICommandInputStream
    {
    public:
        ICommandInputStream() = default;
        ICommandInputStream(const ICommandInputStream&) = default;
        ICommandInputStream &operator=(const ICommandInputStream&) = default;
        virtual ~ICommandInputStream() = default;

    public:
        // Read the next line on input
        virtual std::string nextLine() = 0;
    };
}

#endif //GOMOKU_ICOMMANDINPUTSTREAM_HPP
