#include "Border.h"

Border::Border(int inputX, int inputY, int inputWidth, int inputHeight){
  x=inputX;
  y=inputY;
  width=inputWidth;
  height=inputHeight;
}

void Border::collisionBlock(Robot &robot){
  if(x>robot.getX()){
    robot.setX(x);
    robot.setVelocityX(0);
    robot.setCanIMoveLeft(false);
  }
  if(width<robot.getX2()){
    robot.setX(width-robot.getWidth());
    robot.setVelocityX(0);
    robot.setCanIMoveRight(false);
  }
}

bool Border::collisionGameOver(Robot &robot){
  if(height<robot.getY()){
    return true;
  }else{
    return false;
  }
}

int Border::getX(){
  return x;
}

int Border::getY(){
  return y;
}

int Border::getWidth(){
  return width;
}

int Border::getHeight(){
  return height;
}
