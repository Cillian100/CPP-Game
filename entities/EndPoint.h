#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Robot.h"
#include <string>
#pragma once

class EndPoint : public Square{
 public:
  sf::Sprite getSprite();
  void setSprite();
  bool collision(Robot &robot);
  int middleX();
  void setStuffPodge(int inputX, int inputY, int inputWidth, int inputHeight);
  EndPoint(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
  sf::Texture textureUno;
  sf::Sprite spriteUno;  
};
