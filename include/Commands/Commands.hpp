//
// Created by Mathias on 29/11/2017.
//

#ifndef GOMOKU_COMMANDS_HPP
#define GOMOKU_COMMANDS_HPP

namespace gmk
{
    enum Commands
    {
        START, // Server
        END, // Server
        OK, // Client
        TURN, // Server
        BEGIN, // Server
        BOARD, // Server
        INFO, // Server
        ABOUT, // Client
        UNKNOWN, // Client
        ERROR_CMD, // Client
        MESSAGE, // Client
        DEBUG_CMD // Client
    };
}

#endif //GOMOKU_COMMANDS_HPP
