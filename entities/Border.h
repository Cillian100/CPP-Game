#include <SFML/Graphics.hpp>
#include "Robot.h"

#pragma once

class Border : public Square{
 public:
  Border(int inputX, int inputY, int inputWidth, int inputHeight);

  bool collisionGameOver(Robot &robot);
  void collisionBlock(Robot &robot);
  
 private:
  int x;
  int y;
  int height;
  int width;  
};
