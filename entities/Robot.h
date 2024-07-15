#include <SFML/Graphics.hpp>
#pragma once

class Robot{
 public:
  int getX();
  int getX2();
  int getY();
  int getY2();
  int getWidth();
  int getHeight();
  bool getJump();
  float getVelocityX();
  float getVelocityY();
  void setX(int inputX);
  void setY(int inputY);
  void setVelocityX(float input);
  void setVelocityY(float input);
  void setJump(bool input);
  void userInput();
  void userMovement();
  void gameLoop();
  void gravity();
  sf::Sprite getSprite();
  Robot(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  
  int x;
  int y;
  int width;
  int height;
  float velocityX;
  float velocityY;

  bool canIJump;

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