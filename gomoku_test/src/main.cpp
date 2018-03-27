//
// Created by brd6 on 27/11/2017.
//

#include <Gomoku.hpp>
#include <iostream>
#include "Exception/GomokuException.hpp"

int main(int ac, char const **av)
{
  Gomoku gomoku;

  try {
    gomoku.run();
  }
  catch (gmk::GomokuException &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}