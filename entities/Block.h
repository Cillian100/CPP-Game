#include <SFML/Graphics.hpp>
#include "Robot.h"
#include "Square.h"
#include <string>
#pragma once

class Block : public Square{
 public:
  int getNumOfSprites();
  void gameLoop(Robot &robot);
  sf::Sprite getSprite();
  sf::Sprite getSprite2(int apple);
  void setSprite();
  void setStuffBlock(int inputX, int inputY, int inputHeight, int inputWidth, int inputNumOfSprites, int inputSpriteDirection);
  void collision(Robot &robot);
  Block(int inputX, int inputY, int inputHeight, int inputWidth, int inputNumOfSprites, int inputSpriteDirection);
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::Sprite spriteArray[5];
  int numOfSprites;
  int spriteDirectionInt;
  
  enum spriteDirection{
    SPRITE_UP,
    SPRITE_DOWN,
    SPRITE_RIGHT,
    SPRITE_LEFT
  };
};
