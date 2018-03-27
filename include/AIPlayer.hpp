//
// Created by jonat on 29/11/2017.
//

#ifndef GOMOKU_AIPLAYER_HPP
#define GOMOKU_AIPLAYER_HPP

#include "MinMax/MinMax.hpp"
#include "BasePlayer.hpp"

namespace gmk
{
    class   AIPlayer : public BasePlayer
    {
    private:
        algo::MinMax    mMinMax;

    public:
        AIPlayer() : mMinMax(getSymbol()) {}

        inline int play(Gameboard const &gameboard) override { return (mMinMax.whatToPlay(gameboard)); }
    };
}

#endif //GOMOKU_AIPLAYER_HPP
