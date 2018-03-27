//
// Created by lucas on 04/12/2017.
//

#include <iostream>
#include "MinMax/MinMax.hpp"
#include "Gameboard.hpp"

namespace gmk {
    namespace algo {
        int getValue(int length, int open) {
            if (length >= 5)
            {
                if (open == 2)
                    return (1002);
                if (open == 1)
                    return (1001);
                return (1000);
            }
            if (length == 4 && open == 2)
                return (900);
            if (length == 4 && open == 1)
                return (800);
            if (length == 3 && open == 2)
                return (700);
            if (length == 3 && open == 1)
                return (50);
            if (length == 2 && open == 2)
                return (5);
            if (length == 2 && open == 1)
                return (4);
            if (length == 1 && open == 2)
                return (2);
            if (length == 1 && open == 1)
                return (1);
            return (0);
        }

        int checkVertical(Gameboard const &board, PlayerSymbol player, int x, int y) {
            int length = -1;
            int open = 0;
            int y_save = y;

            /*
            while (y >= 0 && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                y--;
                ++length;
            }
            if (y >= 0 && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            y = y_save;
            while (y < board.getHeight() && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                y++;
                ++length;
            }
            if (y <= board.getHeight() && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;*/
            while (y >= 0 && board.getBoard()[board.getCoordinate(x, y)] == player) {
                ++length;
                --y;
            }
            if (y >= 0 && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            y = y_save;
            while (y < board.getHeight() && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                y++;
                ++length;
            }
            if (y < board.getHeight() && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            return (getValue(length, open));
        }

        int checkHorizontal(Gameboard const &board, PlayerSymbol player, int x, int y) {
            int length = -1;
            int open = 0;
            int x_save = x;

            while (x >= 0 && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                x--;
                ++length;
            }
            if (x >= 0 && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            x = x_save;
            while (x < board.getWidth() && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                x++;
                ++length;
            }
            if (x < board.getWidth() && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            //std::cout << "HZ: " << length << "\n";
            return (getValue(length, open));
        }

        int checkLeftDiagonal(Gameboard const &board, PlayerSymbol player, int x, int y) {
            int length = -1;
            int open = 0;
            int x_save = x;
            int y_save = y;

            while ((x >= 0 && y >= 0) && board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                x--;
                y--;
                ++length;
            }
            if ((x >= 0 && y >= 0) && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            x = x_save;
            y = y_save;
            while ((x < board.getWidth() && y < board.getHeight()) &&
                   board.getBoard()[board.getCoordinate(x, y)] == player)
            {
                x++;
                y++;
                ++length;
            }
            if ((x < board.getWidth() && y < board.getHeight()) &&
                board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            //std::cout << "Length LD: " << length << "\n";
            return (getValue(length, open));
        }

        int checkRightDiagonal(Gameboard const &board, PlayerSymbol player, int x, int y) {
            int length = -1;
            int open = 0;
            int x_save = x;
            int y_save = y;

            while ((x < board.getWidth() && y >= 0) && board.getBoard()[board.getCoordinate(x, y)] == player) {
                ++length;
                ++x;
                --y;
            }
            if ((x < board.getWidth() && y >= 0) && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            x = x_save;
            y = y_save;
            while ((x >= 0 && y < board.getHeight()) && board.getBoard()[board.getCoordinate(x, y)] == player) {
                --x;
                ++y;
                ++length;
            }
            if ((x >= 0 && y < board.getHeight()) && board.getBoard()[board.getCoordinate(x, y)] == DEFAULT_CASE)
                ++open;
            //std::cout << "Length RD: " << length << "\n";
            return (getValue(length, open));
        }

        int MinMax::valuateCase(Gameboard const &board, int pos) const{
            int x;
            int y;
            int maxValue = 0;
            int ret;
            PlayerSymbol player;

            player = board.getLastPlayerSymbol();
            /*std::cout << "PLAYER : " << player << "\n";*/
            board.getCoordinate(pos, x, y);
            if ((x == board.getWidth() / 2 && y == board.getHeight() / 2) ||
                    (x == board.getWidth() / 2 - 1 && y == board.getHeight() / 2))
                maxValue = 3;
            if ((ret = checkVertical(board, player, x, y)) > maxValue)
                maxValue = ret;
            if ((ret = checkHorizontal(board, player, x, y)) > maxValue)
                maxValue = ret;
            if ((ret = checkLeftDiagonal(board, player, x, y)) > maxValue)
                maxValue = ret;
            if ((ret = checkRightDiagonal(board, player, x, y)) > maxValue)
                maxValue = ret;
            //std::cout << "MaxValue ValuateCase : " << maxValue << "\n";
            //board.show();
            //std::cout << "\n\n";
            /*if (maxValue > 2)
                std::cout << maxValue << std::endl;*/

            //std::cout << x << std::endl;
            return (maxValue);
        }
    }
}