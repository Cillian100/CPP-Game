#include "Level_3.h"
#include <iostream>
using namespace std;

Level_3::Level_3(sf::RenderWindow& win) :
  window(win),
  LevelTemplate(win)
{    
  if(!backgroundTexture.loadFromFile("Graphics/backgroundLevel_1.jpg")){
    printf("Couldn't load level one background");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);

  border.setStuffPodge(0,0,1700,650);
  
  blockNumber=6;
  block[0].setStuffBlock(0,500,400,100,4,2);
  block[1].setStuffBlock(400,400,100,200,2,1);
  block[2].setStuffBlock(800,400,100,200,2,1);
  block[3].setStuffBlock(900,500,400,100,4,2);
  block[4].setStuffBlock(1300,100,100,500,5,1);
  block[5].setStuffBlock(1400,100,300,100,3,2);

  numberOfInfoButtons=3;
  infoButton[0].setStuff(10, 490, 80, 10, 0);
  infoButton[1].setStuff(210, 490, 80, 10, 1);
  infoButton[2].setStuff(1110, 490, 80, 10, 2);

  currentLevel=3;
  maxNumberOfRobotClones=1;
}

Level_3::~Level_3(){
  printf("destroyed level 3\n");
}

int Level_3::gameLoop(){
  if(templateLoop()==100){
    return 100;
  }
  Robot robotArray[]={robot, robotClone[0]};
  templateScrolling();  
  templateRender();
  window.display();
  
  gameLoop();

  return 3;
}
