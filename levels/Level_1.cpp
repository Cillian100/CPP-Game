#include "Level_1.h"
#include <iostream>
using namespace std;

Level_1::Level_1(sf::RenderWindow& win) :
  window(win),
  robot(0,200,70,100),
  border(0, 0, 800, 600),
  infoButton(10, 490, 80, 10)
{
  if(!backgroundTexture.loadFromFile("Graphics/backgroundLevel_1.jpg")){
    printf("Couldn't load level one background\n");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);

  if(!gameOverTexture.loadFromFile("Graphics/GameOverScreen.png")){
    printf("Couldn't load game over screen");
  }
  gameOverSprite.setTexture(gameOverTexture);
  gameOverSprite.setTextureRect(sf::IntRect(0,0,800,600));
  gameOverSprite.setColor(sf::Color(255,255,255,150));
  gameOverSprite.setPosition(0,0);
}

void Level_1::gameOver(){
  window.clear();
  window.draw(gameOverSprite);
  window.display();
  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    
  }
  robot.setPosition(0, 200, 0, 0);
}

int Level_1::gameLoop(){  
  robot.gameLoop();
  if(border.collisionGameOver(robot)){
    gameOver();
  }
  border.collisionBlock(robot);
  infoMessage=infoButton.collision(robot);
  for(int a=0;a<9;a++){
    block[a].gameLoop(robot);
  }

  robot.setSprite();
  return render();
}

int Level_1::render(){
  window.clear();
  
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  window.draw(infoButton.getSprite());
  for(int a=0;a<9;a++){
    window.draw(block[a].getSprite());
  }
  
  window.display();
}
