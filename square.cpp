#include "square.h"

square::square(int ex, int why, int wid, int hei){
  x=ex;
  y=why;
  width=wid;
  height=hei;  
}

int square::getX(){
  return x;
}

int square::getY(){
  return y;
}

void square::setX(int ex){
  x=ex;
}

void square::setY(int why){
  y=why;
}

int square::getX2(){
  return x+width;
}

int square::getY2(){
  return y+height;
}

int square::getHeight(){
  return height;
}

int square::getWidth(){
  return width;
}

float square::getVelocityX(){
  return velocityX;
}

float square::getVelocityY(){
  return velocityY;
}

void square::setVelocityX(float velocity){
  if(velocity>8){
    velocityX=8;
  }else{
    velocityX=velocity;
  }
}

void square::setVelocityY(float velocity){
  if(velocity>12){
    velocityY=12;
  }else{
    velocityY=velocity;
  }
}
