#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Robot.h"
#include <string>
//using namepsace std;
#pragma once

class EndPoint : public Square{
 public:
  sf::Sprite getSprite();
  void setSprite();
  void collision(Robot &robot);
  EndPoint(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
  sf::Texture textureUno;
  sf::Sprite spriteUno;  
};
