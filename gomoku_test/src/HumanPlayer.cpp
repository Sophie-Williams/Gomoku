//
// Created by brd6 on 27/11/2017.
//

#include <iostream>
#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(PlayerSymbol symbol) :
 	BasePlayer(symbol),
	mChooseX(-1),
	mChooseY(-1)
{

}

int HumanPlayer::play(Gameboard const &gameboard)
{
  askCoordinate(gameboard);

  return gameboard.getCoordinate(mChooseX, mChooseY);
}

void HumanPlayer::askCoordinate(Gameboard const &gameboard)
{
  bool correctCoordinate = false;
  do
    {
      askCoordinateX(gameboard);
      askCoordinateY(gameboard);

      correctCoordinate = gameboard.isFree(mChooseX, mChooseY);
      if (!correctCoordinate)
	{
	  std::cout << "Invalid coordinate" << std::endl;
	}

    } while (!correctCoordinate);
}

void HumanPlayer::askCoordinateX(Gameboard const &gameboard)
{
  mChooseX = -1;
  bool fail;
  do {
      std::cout << "Enter x: " << std::endl;
      std::cout << ">> ";
      fail = !(std::cin >> mChooseX);
      if (fail)
	{
	  std::cin.clear();
	  std::cin.ignore();
	}

    } while (fail || mChooseX <= -1 || mChooseX > gameboard.getWidth());
}

void HumanPlayer::askCoordinateY(Gameboard const &gameboard)
{
  mChooseY = -1;
  bool fail;
  do {
      std::cout << "Enter y: " << std::endl;
      std::cout << ">> ";
      fail = !(std::cin >> mChooseY);

      if (fail)
	{
	  std::cin.clear();
	  std::cin.ignore();
	}

    } while (fail || mChooseY <= -1 || mChooseY > gameboard.getHeight());
}
