//
// Created by brd6 on 27/11/2017.
//

#include "BasePlayer.hpp"

BasePlayer::BasePlayer(PlayerSymbol symbol) :
	mSymbol(symbol)
{
}

void BasePlayer::setSymbol(PlayerSymbol symbol)
{
  mSymbol = symbol;
}

PlayerSymbol BasePlayer::getSymbol() const
{
  return mSymbol;
}
