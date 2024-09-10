#include "EndPoint.h"

EndPoint::EndPoint(int inputX, int inputY, int inputWidth, int inputHeight) :
  Square(inputX, inputY, inputWidth, inputHeight)
{

  if(!textureUno.loadFromFile("Graphics/endPoint.png")){
    printf("Couldn't load endPoint.png");
  }
  spriteUno.setTexture(textureUno);
  spriteUno.setTextureRect(sf::IntRect(0,0,inputWidth,inputHeight));
  spriteUno.setColor(sf::Color(255,255,255,255));
  spriteUno.setPosition(inputX, inputY);
}

sf::Sprite EndPoint::getSprite(){
  return spriteUno;
}

void EndPoint::setSprite(){
}

int EndPoint::middleX(){
  return (getX()+getX2() )/2;
}

void EndPoint::setStuffPodge(int inputX, int inputY, int inputWidth, int inputHeight){
  setX(inputX);
  setY(inputY);
  setWidth(inputWidth);
  setHeight(inputHeight);
  spriteUno.setPosition(inputX, inputY);
  spriteUno.setTextureRect(sf::IntRect(0,0,inputWidth, inputHeight));
}

bool EndPoint::collision(Robot &robot){
  if(  getY()<=robot.getY() && getY2()>=robot.getY2() && middleX()>robot.getX() && middleX()<robot.getX2() ){
    printf("Collision! \n");
    return true;
  }else{
    //    printf("Not!\n");
    return false;
  }
}
