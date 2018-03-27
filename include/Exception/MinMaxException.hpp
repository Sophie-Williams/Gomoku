//
// Created by jonat on 27/11/2017.
//

#ifndef GOMOKU_MINMAXEXCEPTION_HPP
#define GOMOKU_MINMAXEXCEPTION_HPP

#include "GomokuException.hpp"

namespace gmk
{
    class MinMaxException : public GomokuException
    {
    public:
        explicit MinMaxException(const std::string &msg) : GomokuException(msg) {}
    };
}

#endif //GOMOKU_MINMAXEXCEPTION_HPP
