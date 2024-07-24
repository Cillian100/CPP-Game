#include <SFML/Graphics.hpp>
#include "Square.h"
#pragma once

class Robot : public Square{
 public:
  bool getJump();
  float getVelocityX();
  float getVelocityY();
  void setVelocityX(float input);
  void setVelocityY(float input);
  void setJump(bool input);
  void setCanIMoveRight(bool input);
  void setCanIMoveLeft(bool input);
  void setPosition(int inputX, int inputY, int inputVelX, int inputVelY);
  void userInput();
  void userMovement();
  void gameLoop();
  void gravity();
  sf::Sprite getSprite();
  void setSprite();
  Robot(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  float velocityX;
  float velocityY;

  bool canIJump;
  bool canIMoveRight;
  bool canIMoveLeft;
  
  int playerHorizontal;
  int playerJump;
  enum playerHorizontalEnum{
    RIGHT,
    LEFT,
    HORIZONTAL_DEFAULT
  };

  enum playerJumpEnum{
    JUMP_UP,
    JUMP_DEFAULT
  };
};
