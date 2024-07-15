#include "Level_1.h"

Level_1::Level_1(sf::RenderWindow& win) :
  window(win),
  robot(0,200,70,100),
  block_1(0, 500, 100, 100),
  block_2(100, 500, 100, 100),
  block_3(200, 400, 100, 100)
{
  if(!backgroundTexture.loadFromFile("Graphics/backgroundLevel_1.jpg")){
    printf("Couldn't load level one background\n");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);
}

int Level_1::gameLoop(){
  robot.gameLoop();
  block_1.gameLoop(robot);
  block_2.gameLoop(robot);
  block_3.gameLoop(robot);
  return render();
}

int Level_1::render(){
  window.clear();
  
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  window.draw(block_1.getSprite());
  window.draw(block_2.getSprite());
  window.draw(block_3.getSprite());
  
  window.display();
}
