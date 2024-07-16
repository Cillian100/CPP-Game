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

void Robot::setCanIMoveRight(bool input){
  canIMoveRight=input;
}

void Robot::setCanIMoveLeft(bool input){
  canIMoveLeft=input;
}

void Robot::setVelocityY(float input){
  velocityY=input;
}

void Robot::setVelocityX(float input){
  velocityX=input;
}

void Robot::setPosition(int inputX, int inputY, int inputVelX, int inputVelY){
  x=inputX;
  y=inputY;
  velocityX=inputVelX;
  velocityY=inputVelY;
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
  canIJump=false;
  canIMoveRight=true;
  canIMoveLeft=true;
  //  cout << "Vel | " << velocityY << " | Pos | " << y << endl;
  //  cout << "Hor vel = " << velocityX << " | pos = " << x << endl;
}

void Robot::gravity(){
  if(getVelocityY()<12){
    setVelocityY(getVelocityY() + 0.4);
  }

  if(canIJump){
    setVelocityY(0);
  }
}

void Robot::userMovement(){
  if(playerHorizontal==RIGHT){
    setVelocityX(7);
  }
  if(playerHorizontal==LEFT){
    setVelocityX(-7);
  }
  if(playerHorizontal==HORIZONTAL_DEFAULT){
    setVelocityX(0);
  }

  if(playerJump==JUMP_UP && getJump()){
    setVelocityY(-12);
  }

  setY(getY() + getVelocityY());
  setX(getX() + getVelocityX());
  //  sprite.setPosition(getX(), getY());
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

void Robot::setSprite(){
  sprite.setPosition(getX(), getY());
}
