//
// Created by brd6 on 27/11/2017.
//

#include <cstring>
#include <stdexcept>
#include <iostream>
#include "Gameboard.hpp"

Gameboard::Gameboard(int width, int height) :
        mWidth(width),
        mHeight(height),
        mLastPlayerSymbol(PlayerSymbol::DEFAULT_CASE),
        mLastCoordinate(-1)
{
  initialize();
}

void Gameboard::initialize()
{
  if (mWidth < MIN_WIDTH || mHeight < MIN_HEIGHT)
    throw std::logic_error("Size must be bigger than " + std::to_string(MIN_WIDTH) + "," + std::to_string(MIN_HEIGHT));

  createBoard();
}

void Gameboard::createBoard()
{
  mBoard = new char[mWidth * mHeight];

  std::memset(mBoard, PlayerSymbol::DEFAULT_CASE, mWidth * mHeight);
}

int Gameboard::getCoordinate(int x, int y) const
{
  return x + mWidth * y;
}

Gameboard::~Gameboard()
{
  delete mBoard;
}

void Gameboard::show() const
{
  for (int y = 0; y < mHeight; ++y)
  {
    for (int x = 0; x < mWidth; ++x)
    {
      auto i = getCoordinate(x, y);
      std::cout << mBoard[i];
    }

    std::cout << std::endl;
  }
}

bool Gameboard::put(PlayerSymbol symbol, int x, int y)
{
  auto i = getCoordinate(x, y);

  return put(symbol, i);
}

char const *Gameboard::getBoard() const
{
  return mBoard;
}

int Gameboard::getWidth() const
{
  return mWidth;
}

int Gameboard::getHeight() const
{
  return mHeight;
}

bool Gameboard::put(PlayerSymbol symbol, int i)
{
  if (!isFree(i))
    return false;

  mBoard[i] = symbol;
  mLastPlayerSymbol = symbol;
  mCoordinateHistories.push(i);

  return true;
}

void Gameboard::unput(int i)
{
    mBoard[i] = DEFAULT_CASE;
}

bool Gameboard::checkMatchOnHorizontal() const
{
  return checkMatchOnHorizontalRight() || checkMatchOnHorizontalLeft();
}

bool Gameboard::checkMatchOnVertical() const
{
  return checkMatchOnVerticalTop() || checkMatchOnVerticalBottom();
}

bool Gameboard::checkMatchOnDiagonal() const
{
  return checkMatchOnDiagonalLeftDown() ||
         checkMatchOnDiagonalLeftUp() ||
         checkMatchOnDiagonalRightDown() ||
         checkMatchOnDiagonalRightUp();
}

bool Gameboard::isMatch() const
{
  return (mCoordinateHistories.back() > 0 && mLastPlayerSymbol != PlayerSymbol::DEFAULT_CASE) &&
         (checkMatchOnHorizontal() ||
          checkMatchOnVertical() ||
          checkMatchOnDiagonal());
}

PlayerSymbol Gameboard::getLastPlayerSymbol() const
{
  return mLastPlayerSymbol;
}

void Gameboard::getCoordinate(int i, int &x, int &y) const
{
  x = i % mWidth;
  y = i / mWidth;
}

bool Gameboard::checkMatchOnHorizontalRight() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (int i = x; i < mWidth; ++i)
  {
    auto k = getCoordinate(i, y);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnHorizontalLeft() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (int i = x; i > 0; --i)
  {
    auto k = getCoordinate(i, y);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}


bool Gameboard::isFree(int x, int y) const
{
  auto i = getCoordinate(x, y);

  return isFree(i);
}

bool Gameboard::isFree(int i) const
{
  return (i >= 0 && i < mWidth * mHeight) && (mBoard[i] == PlayerSymbol::DEFAULT_CASE);
}

bool Gameboard::checkMatchOnVerticalTop() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (int i = y; i > 0; --i)
  {
    auto k = getCoordinate(x, i);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH - 1)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnVerticalBottom() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (int i = y; i < mHeight; ++i)
  {
    auto k = getCoordinate(x, i);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH - 1)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnDiagonalLeftDown() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (; y < mHeight && x > 0; ++y, --x)
  {
    auto k = getCoordinate(x, y);

    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnDiagonalLeftUp() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (; y > 0 && x < mWidth; --y, ++x)
  {
    auto k = getCoordinate(x, y);

    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnDiagonalRightDown() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (; y < mHeight && x < mWidth; ++y, ++x)
  {
    auto k = getCoordinate(x, y);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}

bool Gameboard::checkMatchOnDiagonalRightUp() const
{
  int x;
  int y;
  int cpt = 0;

  getCoordinate(mCoordinateHistories.back(), x, y);

  for (; y > 0 && x > 0; --y, --x)
  {
    auto k = getCoordinate(x, y);
    if (mBoard[k] != mLastPlayerSymbol)
      break;
    cpt++;
    if (cpt >= MATCH_LENGTH)
      return true;
  }
  return false;
}

Gameboard &Gameboard::operator=(Gameboard const &obj)
{
  this->mHeight = obj.mHeight;
  this->mWidth = obj.mWidth;
  this->mLastPlayerSymbol = obj.mLastPlayerSymbol;
  this->mCoordinateHistories = obj.mCoordinateHistories;

  initialize();

  std::strncpy(this->mBoard, obj.mBoard, this->mWidth * this->mHeight);

  return *this;
}

Gameboard::Gameboard(Gameboard const &obj) :
        mWidth(obj.mWidth),
        mHeight(obj.mHeight),
        mLastPlayerSymbol(obj.mLastPlayerSymbol),
        mCoordinateHistories(obj.mCoordinateHistories)
{
  initialize();
  std::strncpy(this->mBoard, obj.mBoard, this->mWidth * this->mHeight);
}

void Gameboard::undo()
{
  if (mCoordinateHistories.empty())
    return;

  auto i = mCoordinateHistories.back();

  mCoordinateHistories.pop();

  mBoard[i] = PlayerSymbol::DEFAULT_CASE;
}

int Gameboard::getSize() const
{
  return mWidth * mHeight;
}

PlayerSymbol Gameboard::getActualPlayerSymbol() const
{
  return getLastPlayerSymbol() == PlayerSymbol::BLACK_CASE ? PlayerSymbol::WHITE_CASE : PlayerSymbol::BLACK_CASE;
}
