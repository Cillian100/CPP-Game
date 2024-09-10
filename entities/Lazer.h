#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Robot.h"
#include <string>
#pragma once

class Lazer : public Square{
 public:
  sf::Sprite getSprite();
  void setSprite();
  void buttonCollision(Robot &robot);
  void lazerCollision(Robot &robot);
  sf::Sprite getSpriteUno(int apple);
  sf::Sprite getSpriteDos(int apple);
  sf::Sprite getButtonSprite();
  int getNumberOfSprites();
  bool collision();
  int middleX();
  int getButtonX();
  int getButtonX2();
  int getButtonY();
  int getButtonY2();
  int getLazerX();
  int getLazerX2();
  int getLazerY();
  int getLazerY2();
  Lazer(int inputX, int inputY, int inputWidth, int inputHeight, int inputNumberOfSprites, int inputDirectionOfSprites, int buttonX, int buttonY);
 private:
  int numberOfSprites;
  int directionOfSprites;
  int buttonX;
  int buttonY;
  int buttonWidth;
  int buttonHeight;
    
		     
  sf::Texture textureUno;
  sf::Texture textureDos;
  sf::Sprite spriteUno[2];
  sf::Sprite spriteDos[10];

  sf::Texture textureButtonUnPressed;
  sf::Texture textureButtonPressed;
  sf::Sprite spriteButton;
};
