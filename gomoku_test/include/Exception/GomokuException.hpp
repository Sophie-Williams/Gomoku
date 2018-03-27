//
// Created by jonat on 27/11/2017.
//

#ifndef GOMOKU_GOMOKUEXCEPTION_HPP
#define GOMOKU_GOMOKUEXCEPTION_HPP

#include <string>

namespace gmk
{

    class GomokuException : public std::exception
    {
    private:
        std::string mMsg;

    public:
        explicit GomokuException(const std::string &msg) : mMsg(msg) {}

    public:
        const char *what() const throw() override { return (mMsg.c_str()); }
    };

}

#endif //GOMOKU_GOMOKUEXCEPTION_HPP
