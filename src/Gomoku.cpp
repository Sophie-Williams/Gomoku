//
// Created by brd6 on 27/11/2017.
//

//#include <iostream>
#include "AIPlayer.hpp"
#include "Gomoku.hpp"

Gomoku::Gomoku():
	mGameboard(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT),
	mRunning(false)
{
  initialize();
}

void Gomoku::run()
{
  mRunning = true;

  showWelcomeMessage();

  while (mRunning)
    {
      changePlayerTurn();

      auto &currentPlayer = mPlayers[mCurrentPlayerIndex];

      askPlayerToPlay(currentPlayer);

      //mGameboard.show();
      if (mGameboard.isMatch())
	{
	  mRunning = false;
	  //std::cout << "END! " << (char)mGameboard.getLastPlayerSymbol() << std::endl;
	}
    }
}

void Gomoku::initialize()
{
  mPlayers.push_back(std::make_unique<HumanPlayer>());
  mPlayers.back()->setSymbol(PlayerSymbol::BLACK_CASE);

  //std::cout << "player1 symbol: " << (char)PlayerSymbol::BLACK_CASE << std::endl;

  mPlayers.push_back(std::make_unique<gmk::AIPlayer>());
  mPlayers.back()->setSymbol(PlayerSymbol::WHITE_CASE);

  //std::cout << "player2 symbol: " << (char)PlayerSymbol::WHITE_CASE << std::endl;

  mCurrentPlayerIndex = 0;
}

void Gomoku::showWelcomeMessage()
{
  //std::cout << "Welcome!" << std::endl;

  //mGameboard.show();
}

void Gomoku::askPlayerToPlay(std::unique_ptr<BasePlayer> &player)
{
  bool success = false;

  do
    {
      auto pos = player->play(mGameboard);

      success = mGameboard.put(player->getSymbol(), pos);

//      if (!success)
//	std::cout << "Invalid coordinate" << std::endl;

    } while (!success);

}

void Gomoku::changePlayerTurn()
{
  mCurrentPlayerIndex = (mCurrentPlayerIndex + 1) % 2;

  //std::cout << "Player" << mCurrentPlayerIndex + 1 << " turn!" << std::endl;
}

