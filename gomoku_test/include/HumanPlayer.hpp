//
// Created by brd6 on 27/11/2017.
//

#ifndef _HumanPlayer_H_
#define _HumanPlayer_H_

#include "BasePlayer.hpp"

class HumanPlayer :
	public BasePlayer
{
 private:
  int mChooseX{};
  int mChooseY{};

 public:
  explicit HumanPlayer(PlayerSymbol symbol);

  int play(Gameboard const &gameboard) override;

 private:
  void askCoordinate(Gameboard const &gameboard);
  void askCoordinateX(Gameboard const &gameboard);
  void askCoordinateY(Gameboard const &gameboard);
};

#endif /* !_HumanPlayer_H_ */