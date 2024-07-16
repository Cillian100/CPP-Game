#include "Block.h"

Block::Block(int inputX, int inputY, int inputHeight, int inputWidth){
  x=inputX;
  y=inputY;
  height=inputHeight;
  width=inputWidth;

  if(!texture.loadFromFile("Graphics/Block.png")){
    printf("Couldn't load Graphics/Block.png \n");
  }

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0,0,100,100));
  sprite.setColor(sf::Color(255,255,255,255));
  sprite.setPosition(0,0);
}

void Block::collision(Robot &robot){
  if(getY()<robot.getY2() && getX2()>robot.getX() && getX()<robot.getX2()){

    if(getY()<getY2()+5){
      robot.setY(getY() - robot.getHeight() + 1);
      robot.setVelocityY(0);
      robot.setJump(true);
    }
  }
}

void Block::gameLoop(Robot &robot){
  setSprite();
  collision(robot);
}

sf::Sprite Block::getSprite(){
  return sprite;
}

int Block::getX(){
  return x;
}

int Block::getX2(){
  return x+width;
}

int Block::getY(){
  return y;
}

int Block::getY2(){
  return y+height;
}

void Block::setSprite(){
  sprite.setPosition(getX(), getY());
}
