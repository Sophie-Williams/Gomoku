//
// Created by brd6 on 27/11/2017.
//

#ifndef _Gomoku_H_
#define _Gomoku_H_

#include <memory>
#include <vector>
#include "Gameboard.hpp"
#include "HumanPlayer.hpp"

class Gomoku
{
 private:
  const int DEFAULT_BOARD_WIDTH = 19;
  const int DEFAULT_BOARD_HEIGHT = 19;
  Gameboard mGameboard;
  bool mRunning;
  std::vector<std::unique_ptr<BasePlayer>> mPlayers;
  int mCurrentPlayerIndex;

 public:
  Gomoku();
  virtual ~Gomoku() = default;

  void run();

 private:
  void initialize();
  void showWelcomeMessage();

  void askPlayerToPlay(std::unique_ptr<BasePlayer> &player);

  void changePlayerTurn();
};

#endif /* !_Gomoku_H_ */