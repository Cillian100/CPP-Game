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

  border.setStuffPodge(0,0,1000,1000);
  
  blockNumber=6;
  block[0].setStuffBlock(0,500,400,100,4,2);
  currentLevel=3;
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
  return 3;
}
