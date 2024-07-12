#include <SFML/Graphics.hpp>
#pragma once

class Robot{
 public:
  int getX();
  int getY();
  int getWidth();
  int getHeight();
  sf::Sprite getSprite();
  Robot(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  
  int x;
  int y;
  int width;
  int height;
};
