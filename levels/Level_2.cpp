#include "Level_2.h"
#include <iostream>
using namespace std;

Level_2::Level_2(sf::RenderWindow& win) :
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

  blockNumber=7;
  block[0].setStuffBlock(0, 400, 500, 100, 5, 2);
  block[1].setStuffBlock(800, 400, 500, 100, 5, 2);
  border.setStuff(0, 0, 1200, 1000);
}

int Level_2::gameLoop(){
  templateLoop();
  templateScrolling();  
  templateRender();
}

int Level_2::render(){
  window.clear();
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  window.display();
}

