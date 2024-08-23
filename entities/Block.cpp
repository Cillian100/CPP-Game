#include "Block.h"
#include <algorithm>

Block::Block(int inputX, int inputY, int inputWidth, int inputHeight, int inputNumOfSprites, int inputSpriteDirection)
  :Square(inputX, inputY, inputWidth, inputHeight)
{
  numOfSprites=inputNumOfSprites;
  spriteDirectionInt=inputSpriteDirection;

  if(!texture.loadFromFile("Graphics/Block.png")){
    printf("Couldn't load Graphics/Block.png \n");
  }

  for(int a=0;a<numOfSprites;a++){
    spriteArray[a].setTexture(texture);
    spriteArray[a].setTextureRect(sf::IntRect(0,0,100,100));
    spriteArray[a].setColor(sf::Color(255,255,255,255));
    if(spriteDirectionInt==SPRITE_RIGHT){
      spriteArray[a].setPosition(inputX+(a*100),inputY);
    }
    if(spriteDirectionInt==SPRITE_DOWN){
      spriteArray[a].setPosition(inputX,inputY+(a*100));
    }
  }

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0,0,100,100));
  sprite.setColor(sf::Color(255,255,255,255));
  sprite.setPosition(0,0);
}

void Block::collision(Robot &square){
  if(getX()<square.getX2() && getX2()>square.getX() && getY()<square.getY2() && getY2()>square.getY()){
    int top=abs(getY()-square.getY2());
    int bottom=abs(getY2()-square.getY());
    int right=abs(getX2()-square.getX());
    int left=abs(getX()-square.getX2());
    
    if( (right < top) && (right < left) && (right < bottom) ){
      square.setX(getX2());
    }else if( (left < top) && (left < right) && (left < bottom) ){
      square.setX2(getX());
    }else if( (bottom < top) && (bottom < right) && (bottom < left) ){
      square.setY(getY2());
    }else{
      square.setY2(getY());
      square.setJump(true);
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

sf::Sprite Block::getSprite2(int apple){
  return spriteArray[apple];
}

int Block::getNumOfSprites(){
  return numOfSprites;
}

void Block::setSprite(){
  sprite.setPosition(getX(), getY());
}

void Block::setStuffBlock(int inputX, int inputY, int inputWidth, int inputHeight, int inputNumOfSprites, int inputSpriteDirection){
  setStuff(inputX, inputY, inputWidth, inputHeight);
  numOfSprites=inputNumOfSprites;
  spriteDirectionInt=inputSpriteDirection;

  for(int a=0;a<numOfSprites;a++){
    spriteArray[a].setTexture(texture);
    spriteArray[a].setTextureRect(sf::IntRect(0,0,100,100));
    spriteArray[a].setColor(sf::Color(255,255,255,255));
    if(spriteDirectionInt==SPRITE_RIGHT){
      spriteArray[a].setPosition(inputX+(a*100),inputY);
    }
    if(spriteDirectionInt==SPRITE_DOWN){
      spriteArray[a].setPosition(inputX,inputY+(a*100));
    }
  }
  
}
