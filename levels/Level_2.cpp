#include "Level_2.h"
#include <iostream>
using namespace std;

Level_2::Level_2(sf::RenderWindow& win) :
  window(win),
  LevelTemplate(win),
  lazerUno(500, 400, 300, 100, 3, 1, 310, 390),
  lazerDos(1000, 500, 100, 400, 4, 2, 810, 890)
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
  block[2].setStuffBlock(400, 400, 100, 400, 5, 1);
  block[3].setStuffBlock(400, 900, 900, 100, 9, 2);
  border.setStuffPodge(0, 0, 1300, 1000);
  endPoint.setStuffPodge(1200, 780, 90, 120);
  currentLevel=2;
}

int Level_2::gameLoop(){
  if(templateLoop()!=currentLevel){
    return 3;
  }
  lazerUno.buttonCollision(robot);
  lazerUno.lazerCollision(robot);
  lazerDos.buttonCollision(robot);
  lazerDos.lazerCollision(robot);
  templateScrolling();
  templateRender();

  for(int a=0;a<lazerUno.getNumberOfSprites();a++){
    window.draw(lazerUno.getSpriteDos(a));
  }  
  for(int a=0;a<2;a++){
    window.draw(lazerUno.getSpriteUno(a));
  }
  window.draw(lazerUno.getButtonSprite());
  
  for(int a=0;a<lazerDos.getNumberOfSprites();a++){
    window.draw(lazerDos.getSpriteDos(a));
  }
  for(int a=0;a<2;a++){
    window.draw(lazerDos.getSpriteUno(a));
  }
  window.draw(lazerDos.getButtonSprite());

  window.display();
  printf("%d %d \n", robot.getX(), robot.getY());
  
  return 2;
}

int Level_2::render(){
  window.clear();
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  for(int a=0;a<2;a++){
    window.draw(lazerUno.getSpriteUno(a));
  }
  window.display();
}

