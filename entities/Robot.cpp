#include "Robot.h";
#include <iostream>
using namespace std;

Robot::Robot(int inputX, int inputY, int inputWidth, int inputHeight){
  x=inputX;
  y=inputY;
  width=inputWidth;
  height=inputHeight;

  velocityY=0;
  velocityX=0;

  if(!texture.loadFromFile("Graphics/robot.png")){
    printf("couldn't load robot \n");
  }

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0,0,70,100));
  sprite.setColor(sf::Color(255, 255, 255, 255));
  sprite.setPosition(0,0);
}

int Robot::getX(){
  return x;
}

int Robot::getX2(){
  return x+getWidth();
}

int Robot::getY(){
  return y;
}

int Robot::getY2(){
  return y+getHeight();
}

bool Robot::getJump(){
  return canIJump;
}

float Robot::getVelocityX(){
  return velocityX;
}

float Robot::getVelocityY(){
  return velocityY;
}

void Robot::setX(int inputX){
  x=inputX;
}

void Robot::setY(int inputY){
  y=inputY;
}

void Robot::setJump(bool input){
  canIJump=input;
}

void Robot::setVelocityY(float input){
  velocityY=input;
}

void Robot::setVelocityX(float input){
  velocityX=input;
}

int Robot::getWidth(){
  return width;
}

int Robot::getHeight(){
  return height;
}

void Robot::gameLoop(){
  userInput();
  gravity();
  userMovement();
  cout << "Velocity - " << velocityY << endl;
}

void Robot::gravity(){
  if(getVelocityY()<12){
    setVelocityY(getVelocityY() + 0.4);
  }
}

void Robot::userMovement(){
  if(playerHorizontal==RIGHT){
    setX(getX()+7);
  }
  if(playerHorizontal==LEFT){
    setX(getX()-7);
  }

  if(playerJump==JUMP_UP && getJump()){
    setVelocityY(-12);
  }

  setY(getY() + getVelocityY());
  sprite.setPosition(getX(), getY());
}

void Robot::userInput(){
  playerHorizontal=HORIZONTAL_DEFAULT;
  playerJump=JUMP_DEFAULT;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    playerHorizontal=LEFT;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    playerHorizontal=RIGHT;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    playerJump=JUMP_UP;
  }
}

sf::Sprite Robot::getSprite(){
  return sprite;
}
