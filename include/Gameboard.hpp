//
// Created by brd6 on 27/11/2017.
//

#ifndef _Gameboard_H_
#define _Gameboard_H_

#include <queue>
#include "PlayerSymbol.hpp"

class Gameboard
{
 public:
  const int MIN_WIDTH = 5;
  const int MIN_HEIGHT = 5;
  const int MATCH_LENGTH = 5;

 private:
  int mWidth;
  int mHeight;
  char *mBoard;
  PlayerSymbol mLastPlayerSymbol;
  int mLastCoordinate;
    std::queue <int> mCoordinateHistories;

public:
  explicit Gameboard(int width, int height);
    Gameboard &operator=(Gameboard const &obj);
    Gameboard(Gameboard const &obj);
    ~Gameboard();

private:
  /**
   * Show the gameboard
   */
  void show() const;

public:

  /**
   * Put a player symbol in the gameboard
   * @param symbol
   * @param x
   * @param y
   * @return
   */
  bool put(PlayerSymbol symbol, int x, int y);

  /**
   * Put a player symbol in the gameboard
   * @param symbol
   * @param i
   * @see Gameboard::getCoordinate for computing i param
   * @return
   */
  bool put(PlayerSymbol symbol, int i);

  void  unput(int i);


    /**
   * Get the gameboard
   * @return
   */
  char const *getBoard() const;

  int getCoordinate(int x, int y) const;
  void getCoordinate(int i, int &x, int &y) const;

  int getWidth() const;
  int getHeight() const;

    int getSize() const;

  bool isMatch() const;
  PlayerSymbol getLastPlayerSymbol() const;
    PlayerSymbol getActualPlayerSymbol() const;


    bool isFree(int x, int y) const;
  bool isFree(int i) const;

  void undo();

private:
  void initialize();
  void createBoard();

  bool checkMatchOnHorizontal() const;
  bool checkMatchOnHorizontalRight() const;

  bool checkMatchOnVertical() const;
  bool checkMatchOnDiagonal() const;

  bool checkMatchOnHorizontalLeft() const;

  bool checkMatchOnVerticalTop() const;

  bool checkMatchOnVerticalBottom() const;

    bool checkMatchOnDiagonalLeftDown() const;
    bool checkMatchOnDiagonalLeftUp() const;

    bool checkMatchOnDiagonalRightDown() const;
    bool checkMatchOnDiagonalRightUp() const;
};

#endif /* !_Gameboard_H_ */