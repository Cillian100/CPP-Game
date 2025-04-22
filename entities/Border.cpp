#include "Border.h"

Border::Border(int inputX, int inputY, int inputWidth, int inputHeight)
  : Square(inputX, inputY, inputWidth, inputHeight)
{
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

void Border::setStuffPodge(int inputX, int inputY, int inputWidth, int inputHeight){
  x=inputX;
  y=inputY;
  width=inputWidth;
  height=inputHeight;
}

int Border::getX2(){
  return x+width;
}

int Border::getY2(){
  return y+height;
}