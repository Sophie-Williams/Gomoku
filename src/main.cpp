//
// Created by brd6 on 27/11/2017.
//

#include <algorithm>
#include <fstream>
#include <cmath>
#include <MinMax/MinMax.hpp>
#include "Exception/GomokuException.hpp"
#include "Commands/CommandManager.hpp"

int main(int ac, char const **av)
{
    gmk::CommandManager manager;
    gmk::algo::MinMax   minMax(PlayerSymbol::WHITE_CASE);
    std::shared_ptr<Gameboard> gameboard;
    bool                loop = true;
    int                 saved_size = -1;

    manager.setCommandHandler(gmk::Commands::START, [&saved_size, &minMax, &gameboard, &manager](const gmk::Commands cmd, const std::vector<std::string> args)
    {
        if (args.size() != 2) {
            manager.getWriter()->sendCommand(gmk::Commands::ERROR_CMD, "Unable to start");
            return;
        }
        saved_size = std::stoi(args[1]);
        gameboard = std::make_shared<Gameboard>(saved_size, saved_size);
        manager.getWriter()->sendCommand(gmk::Commands::OK);
    });

    manager.setCommandHandler(gmk::Commands::BOARD, [&manager, &gameboard, &saved_size](const gmk::Commands &cmd, const std::vector<std::string> &args)
    {
        std::vector<std::string> board= gmk::readBoardInputs(manager.getReader()->getInputStream());
        gameboard = std::make_shared<Gameboard>(saved_size, saved_size);
        std::for_each(board.begin(), board.end(), [&gameboard](const std::string &a)
        {
            std::string input[] =
                    {
                            a.substr(0, a.find_first_of(',')),
                            a.substr(a.find_last_of(',') + 1)
                    };
            int *res = gmk::readTurnInput(input[0]);
            PlayerSymbol sym = (input[1] == "1") ? PlayerSymbol::WHITE_CASE : PlayerSymbol::BLACK_CASE;
            gameboard->put(sym, res[0], res[1]);
            delete res;
        });
    });

    gmk::OnCommand playCmd = [&minMax, &gameboard, &manager](const gmk::Commands cmd, const std::vector<std::string> args)
    {
        if (cmd == gmk::Commands::TURN)
        {
            if (args.size() != 2)
                return;
            int *in = gmk::readTurnInput(args[1]);
            gameboard->put(PlayerSymbol::BLACK_CASE/*Récupérer le symbole de l'adversaire*/,
                           in[0], in[1]);
            delete in;
        }
        int pos = minMax.whatToPlay(*gameboard);
        int y = pos / gameboard->getWidth();
        int x = (pos - (y * gameboard->getWidth()));
        manager.getWriter()->sendPlayCommand(x, y);
        gameboard->put(PlayerSymbol::WHITE_CASE, pos);
    };
    manager.setCommandHandler(gmk::Commands::BEGIN, playCmd);
    manager.setCommandHandler(gmk::Commands::TURN, playCmd);

    manager.setCommandHandler(gmk::Commands::END, [&loop] (const gmk::Commands cmd, const std::vector<std::string> args)
    {
        loop = false;
    });

    manager.setCommandHandler(gmk::Commands::UNKNOWN, [&manager](const gmk::Commands cmd, const std::vector<std::string> args)
    {
        manager.getWriter()->sendCommand(gmk::Commands::UNKNOWN);
    });

    while (loop)
        manager.readNextCommand();
    return (0);
}