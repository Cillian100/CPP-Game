#include "RobotClone.h"

RobotClone::RobotClone(int inputX, int inputY, int inputWidth, int inputHeight)
  : Robot(inputX, inputY, inputWidth, inputHeight)
{
  setVelocityX(0);
  setVelocityY(0);

  if(!setTexture("Graphics/evilRobot.png")){
    printf("Couldn't load evil robot \n");
  }

  setSpriteSetUp();
}

void RobotClone::getPosition(){
  //  printf("X %d - Y %d\n", getX(), getY());
}

void RobotClone::automatedInput(char key){
  if(key=='A'){
    setPlayerHorizontal(LEFT);
  }
  if(key=='D'){
    setPlayerHorizontal(RIGHT);
  }
  if(key=='W'){
    setPlayerJump(JUMP_UP);
  }
}

void RobotClone::robotOnRobotCollision(Robot &robot){
  if(getX()<robot.getX2() && getX2()>robot.getX() && getY()<robot.getY2() && getY2()>robot.getY()){
    int top=abs(getY()-robot.getY2());
    int bottom=abs(getY2()-robot.getY());
    int right=abs(getX2()-robot.getX());
    int left=abs(getX()-robot.getX2());
    
    if( (right < top) && (right < left) && (right < bottom) ){
      robot.setX(getX2());
    }else if( (left < top) && (left < right) && (left < bottom) ){
      robot.setX2(getX());
    }else if( (bottom < top) && (bottom < right) && (bottom < left) ){
      robot.setY(getY2());
    }else{
      robot.setY2(getY());
      robot.setJump(true);
    }
  }  
}
