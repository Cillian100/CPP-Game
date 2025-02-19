#include <SFML/Graphics.hpp>
#include "Robot.h"
#include "Square.h"
#include <string>
#pragma once

class Trapdoor : public Square{
 public:
  sf::Sprite getSpriteTrapdoorUno();
  sf::Sprite getSpriteTrapdoorDos();
  sf::Sprite getSpriteTrapdoorButton();
  
  void trapdoorCollision(Robot &robot);
  void buttonCollision(Robot &robot);
  Trapdoor(int inputX, int inputY, int inputWidth, int inpudHeight, int inputButtonX, int inputButtonY);
 private:
  int buttonX;
  int buttonY;
  bool buttonPressed;
  
  sf::Sprite spriteTrapdoorUno;
  sf::Sprite spriteTrapdoorDos;
  sf::Sprite spriteTrapdoorButton;
  sf::Texture textureTrapdoor;
  sf::Texture textureTrapdoorButtonPressed;
  sf::Texture textureTrapdoorButtonUnPressed;
};
