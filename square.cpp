#include "square.h"

square::square(int ex, int why, int len, int wid){
  x=ex;
  y=why;
  length=len;
  width=wid;
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
  return x+length;
}

int square::getY2(){
  return y+width;
}

int square::getLength(){
  return length;
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
