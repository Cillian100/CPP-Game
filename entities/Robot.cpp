#include "Robot.h";
#include <iostream>
using namespace std;

Robot::Robot(int inputX, int inputY, int inputWidth, int inputHeight)
  : Square(inputX, inputY, inputWidth, inputHeight)
{
  velocityY=0;
  velocityX=0;

  if(!setTexture("Graphics/robot.png")){
    printf("couldn't load robot \n");
  }
  setSpriteSetUp();
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

sf::Texture& Robot::getTexture(){
  return texture;
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

bool Robot::setTexture(string classpath){
  return texture.loadFromFile(classpath);
}

void Robot::setSpriteSetUp(){
  sprite.setTexture(getTexture());
  sprite.setTextureRect(sf::IntRect(0,0,70,100));
  sprite.setColor(sf::Color(255, 255, 255, 255));
  sprite.setPosition(0,0);  
}

void Robot::setVelocityY(float input){
  velocityY=input;
}

void Robot::setVelocityX(float input){
  velocityX=input;
}

void Robot::setPosition(int inputX, int inputY, int inputVelX, int inputVelY){
  setX(inputX);
  setY(inputY);
  velocityX=inputVelX;
  velocityY=inputVelY;
}

void Robot::gameLoop(){
  gravity();
  userMovement();
  canIJump=false;
  canIMoveRight=true;
  canIMoveLeft=true;
  playerHorizontal=HORIZONTAL_DEFAULT;
  playerJump=JUMP_DEFAULT;
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

void Robot::userInput(int ticks){
  playerHorizontal=HORIZONTAL_DEFAULT;
  playerJump=JUMP_DEFAULT;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    pairKey=make_pair(ticks, 'A');
    vecOfPairs.push_back(pairKey);
    playerHorizontal=LEFT;
  }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    pairKey=make_pair(ticks, 'D');
    vecOfPairs.push_back(pairKey);
    playerHorizontal=RIGHT;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    pairKey=make_pair(ticks, 'W');
    vecOfPairs.push_back(pairKey);
    playerJump=JUMP_UP;
  }

  cout << "stored: " << vecOfPairs.size() << endl;
}

sf::Sprite Robot::getSprite(){
  return sprite;
}

vector<pair<int, char>> Robot::getVector(){
  return vecOfPairs;
}

void Robot::setVecOfPairsClear(){
  vecOfPairs.clear();
}

void Robot::printVector(){
  for(auto podge : vecOfPairs){
    cout << "jef " << podge.first << " " << podge.second << endl;
  }

  cout << "finnished iterating " << endl;
}

void Robot::setSprite(){
  sprite.setPosition(getX(), getY());
}

void Robot::setXAndWhy(){
  setY(getY() + getVelocityY());
  setX(getX() + getVelocityX());  
}

void Robot::setPlayerHorizontal(int input){
  playerHorizontal=input;
}
void Robot::setPlayerJump(int input){
  playerJump=input;
}
int Robot::getPlayerHorizontal(){
  return playerHorizontal;
}
int Robot::getPlayerJump(){
  return playerJump;
}
