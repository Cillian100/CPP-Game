#include <SFML/Graphics.hpp>
#include "Robot.h"
#pragma once

class Block{
 public:
  int getX();
  int getX2();
  int getY();
  int getY2();
  int getHeight();
  int getWidth();
  void gameLoop(Robot &robot);
  sf::Sprite getSprite();
  void setSprite();
  void collision(Robot &robot);
  Block(int inputX, int inputY, int inputHeight, int inputWidth);
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  
  int x;
  int y;
  int height;
  int width;
};
