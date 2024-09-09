#include <SFML/Graphics.hpp>
#include "Robot.h"

#pragma once

class Border : public Square{
 public:
  Border(int inputX, int inputY, int inputWidth, int inputHeight);
  int getX2();
  bool collisionGameOver(Robot &robot);
  void collisionBlock(Robot &robot);
  void setStuffPodge(int inputX, int inputY, int inputWidth, int inputHeight);
  
 private:
  int x;
  int y;
  int height;
  int width;  
};
