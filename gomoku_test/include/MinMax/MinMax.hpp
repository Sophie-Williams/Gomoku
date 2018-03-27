//
// Created by jonat on 27/11/2017.
//

#ifndef GOMOKU_IMINMAX_HPP
#define GOMOKU_IMINMAX_HPP

#include <cstddef>
#include "PlayerSymbol.hpp"
#include "Gameboard.hpp"

namespace gmk
{
namespace algo
{
    class MinMax
    {
    private:
        int            mDepth;
        PlayerSymbol    mSymbol;

    public:
        explicit MinMax(PlayerSymbol symbol);
        explicit MinMax(const MinMax &) = delete;
        MinMax &operator=(const MinMax &) = delete;
        ~MinMax() = default;

        int             valuateCase(Gameboard const &board, int pos) const;

    public:
        inline void     setDepth(size_t depth) { mDepth = depth; }
        int             whatToPlay(const Gameboard &gameboard);

    private:
        int             min(Gameboard &gameboard, int pos);
        //int             max(Gameboard &gameboard, int depth, int pos);
        int             eval(Gameboard &gameboard, int pos);

    };

}
}

#endif //GOMOKU_IMINMAX_HPP
