#include <SFML/Graphics.hpp>
#include "Square.h"
#include <vector>
using namespace std;

#pragma once

using std::vector;
using std::pair;

class Robot : public Square{
 public:
  bool getJump();
  float getVelocityX();
  float getVelocityY();
  vector<pair<int, char>> getVector();
  sf::Texture& getTexture();
  
  void setVelocityX(float input);
  void setVelocityY(float input);
  void setJump(bool input);
  void setCanIMoveRight(bool input);
  void setCanIMoveLeft(bool input);
  void setPosition(int inputX, int inputY, int inputVelX, int inputVelY);
  bool setTexture(string classPath);
  void setSpriteSetUp();
  void setXAndWhy();
  
  void userInput(int ticks);
  void userMovement();
  void gameLoop();
  void gravity();
  sf::Sprite getSprite();
  void setSprite();
  Robot(int inputX, int inputY, int inputWidth, int inputHeight);

  enum playerHorizontalEnum{
    RIGHT,
    LEFT,
    HORIZONTAL_DEFAULT
  };

  enum playerJumpEnum{
    JUMP_UP,
    JUMP_DEFAULT
  };

  void setPlayerHorizontal(int input);
  void setPlayerJump(int input);
  int getPlayerHorizontal();
  int getPlayerJump();
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  float velocityX;
  float velocityY;

  bool canIJump;
  bool canIMoveRight;
  bool canIMoveLeft;

  vector<pair<int, char>> vecOfPairs;
  pair<int, char> pairKey;
    
  
  int playerHorizontal;
  int playerJump;
};
