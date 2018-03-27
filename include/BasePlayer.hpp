//
// Created by brd6 on 27/11/2017.
//

#ifndef _Player_H_
#define _Player_H_

#include "PlayerSymbol.hpp"
#include "Gameboard.hpp"

class BasePlayer
{
 private:
  PlayerSymbol mSymbol;

 public:
  BasePlayer();
  virtual ~BasePlayer() = default;

  /**
   * Play a turn and return the coordinate in 1D
   * @see GameBoard::getCoordinate to compute the coordinate
   * @param gameboard
   * @return
   */
  virtual int play(Gameboard const &gameboard) = 0;

  void setSymbol(PlayerSymbol symbol);
  PlayerSymbol getSymbol() const;
};

#endif /* !_Player_H_ */