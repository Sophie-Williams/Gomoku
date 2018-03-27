//
// Created by jonat on 27/11/2017.
//

#include <Gameboard.hpp>
#include <iostream>
#include <unistd.h>
#include "MinMax/MinMax.hpp"
#include "Exception/GomokuException.hpp"

namespace gmk {
    namespace algo {
        MinMax::MinMax(PlayerSymbol symbol) : mDepth(1), mSymbol(symbol) {}

        int MinMax::whatToPlay(const Gameboard &gameboard) {
            Gameboard board(gameboard);

            int bestVal = 0;
            int maxVal = 0;
            int minVal = 0;
            int bestMove = 0;
            int worseVal = 100000;
            int worseMove = 0;
            /*int highestVal = 0;
            int highestMove = 0;*/

            int boardSize = board.getHeight() * board.getWidth();
            PlayerSymbol player = mSymbol;

            for (int i = 0; i < boardSize; i++) {
                if (board.put(player, i)) {
                    maxVal = eval(board, i);
                    minVal = min(board, i);
                    /* (maxVal > highestVal)
                    {
                        highestVal = maxVal;
                        highestMove = i;
                    }*/
                    if (minVal < 900 || maxVal >= minVal) {
                        if (maxVal > bestVal) {
                            bestVal = maxVal;
                            bestMove = i;
                        }
                    }
                    else if (minVal < worseVal) {
                        worseVal = minVal;
                        worseMove = i;
                    }
                    board.unput(i);
                }
            }
            if (bestVal > 0)
                return (bestMove);
            /*if (worseVal < 1000)
                return (highestMove);*/
            return (worseMove);
            /*int maxMove = -1000;
            int bestMove = 0;
            int tmpMove = -1;
            int boardSize = board.getHeight() * board.getWidth();
            PlayerSymbol player;

            player = board.getActualPlayerSymbol();
            for (int i = 0; i < boardSize; ++i) {
                if (board.put(player, i)) {
                    //std::cout << "PRONFONDEUR " << mDepth << " player who played : " << board.getLastPlayerSymbol() << std::endl;
                    tmpMove = min(board, mDepth - 1, i);
                    if (tmpMove >= maxMove) {
                        maxMove = tmpMove;
                        bestMove = i;
                    }
                    board.unput(i);
                }
            }

            return (bestMove);*/
        }

        int MinMax::min(Gameboard &gameboard, int pos) {
            PlayerSymbol player = gameboard.getActualPlayerSymbol();
            int boardSize = gameboard.getHeight() * gameboard.getWidth();
            int maxVal = 0;
            int tmp = 0;
            int coef = 0;

            for (int i = 0; i < boardSize; i++) {
                if (gameboard.put(player, i)) {
                    tmp = eval(gameboard, i);
                    if (tmp >= maxVal) {
                        maxVal = tmp;
                        coef = 1;
                    }
                    else if (tmp == maxVal)
                        ++coef;
                    gameboard.unput(i);
                }
            }
            return (maxVal + coef);
/*            int minValue = -1000;
            int tmpValue = -1;
            int boardSize = gameboard.getHeight() * gameboard.getWidth();
            PlayerSymbol player;

            player = gameboard.getActualPlayerSymbol();
            if (depth < 0 || gameboard.isMatch())
                return (eval(gameboard, pos));
            for (int i = 0; i < boardSize; ++i) {
                if (gameboard.put(player, i)) {
                    std::cout << "MIN : PRONFONDEUR " << depth << " player who played : " << gameboard.getLastPlayerSymbol() << std::endl;
                    std::cout << mSymbol << "\n" << BLACK_CASE << "\n" << WHITE_CASE << "\n" << DEFAULT_CASE << "\n";
                    gameboard.show();
                    exit(0);
                    tmpValue = max(gameboard, depth - 1, i);
                    if (tmpValue < minValue)
                        minValue = tmpValue;
                    gameboard.unput(i);
                    //exit(0);
                }
            }
            return (minValue); // * -1 ?*/
        }

        /*int MinMax::max(Gameboard &gameboard, int depth, int pos) {
            int maxValue = -1000;
            int tmpValue = -1;
            int boardSize = gameboard.getHeight() * gameboard.getWidth();
            PlayerSymbol player;

            player = gameboard.getActualPlayerSymbol();
            if (depth < 0 || gameboard.isMatch())
                return (eval(gameboard, pos));
            for (int i = 0; i < boardSize; ++i) {
                if (gameboard.put(player, i)) {
                    //std::cout << "MAX : PRONFONDEUR " << depth << " player who played : " << gameboard.getLastPlayerSymbol() << std::endl;
                    tmpValue = min(gameboard, depth - 1, i);
                    if (tmpValue > maxValue)
                        maxValue = tmpValue;
                    gameboard.unput(i);
                }
            }
            return (maxValue);
        }*/

        int MinMax::eval(Gameboard &gameboard, int pos) {
            /*if (mSymbol == gameboard.getLastPlayerSymbol())
                return (valuateCase(gameboard, pos));
            else
                return (valuateCase(gameboard, pos) * -1);
            }*/
            return (valuateCase(gameboard, pos));
        }
    }
}