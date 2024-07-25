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
  printf("X %d - Y %d\n", getX(), getY());
}

void RobotClone::automatedInput(char key){
  if(key=='A'){
    setPlayerHorizontal(LEFT);
  }
  if(key=='D'){
    setPlayerHorizontal(RIGHT);
    //    playerHorizontal=RIGHT;
  }
  if(key=='W'){
    setPlayerHorizontal(JUMP_UP);
    //    playerJump=JUMP_UP;
  }
}
