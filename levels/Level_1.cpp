#include "Level_1.h"
#include <iostream>
using namespace std;

Level_1::Level_1(sf::RenderWindow& win) :
  window(win),
  LevelTemplate(win)
{
  if(!backgroundTexture.loadFromFile("Graphics/backgroundLevel_2.jpg")){
    printf("Couldn't load level two background");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);

  blockNumber=6;
  block[0].setStuffBlock(0, 600, 500, 100, 5, 2);
  block[1].setStuffBlock(400, 500, 100, 200, 1, 1);
  block[2].setStuffBlock(800, 500, 100, 400, 1, 1);
  block[3].setStuffBlock(800, 600, 500, 100, 5, 2);
  block[4].setStuffBlock(1400, 200, 300, 100, 3, 2);
  block[5].setStuffBlock(1300, 200, 100, 500, 6, 1);

  border.setStuffPodge(0, 0, 1700, 100);
  endPoint.setStuffPodge(1605, 80, 90, 120);
  numberOfLazer=1;
  lazer[0].setStuffLazer(500, 600, 300, 100, 3, 1, 0, 0);
  //  void setStuffLazer(int inputX, int inputY, int inputWidth, int inputHeight, int inputNumberOfSprites, int inputDirectionOfSprites, int buttonX, int buttonY);


  currentLevel=1;
  maxNumberOfRobotClones=1;
}

int Level_1::gameLoop(){
  if(templateLoop()!=currentLevel){
    return LEVEL_2;
  }
  Robot robotArray[]={robot, robotClone[0]};
  templateScrolling();
  templateRender();
  window.display();
  
  return LEVEL_1;
}
