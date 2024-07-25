#include "Level_1.h"
#include <iostream>
using namespace std;

Level_1::Level_1(sf::RenderWindow& win) :
  window(win),
  robot(0,200,70,100),
  robotClone(0, 200, 70, 100),
  border(0, 0, 1300, 600),
  mouse(0, 0, 24, 30)
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

  if(!mouseTexture.loadFromFile("Graphics/mouse.png")){
    printf("Couldn't load mouse.png\n");
  }
  mouseSprite.setTexture(mouseTexture);
  mouseSprite.setTextureRect(sf::IntRect(0,0,24,30));
  mouseSprite.setColor(sf::Color(255,255,255,255));
  mouseSprite.setPosition(0,0);
  clock.restart();

  pairKey=make_pair(0, 'g');
  vecOfPairs.push_back(pairKey);
}

int Level_1::gameLoop(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
    timeLoop();
  }
  printf("podge %d\n", vecOfPairs.at(0));
  if(vecOfPairs.at(0).first==ticks){
  //  robotClone.automatedInput(vecOfPairs.at(0).second);
    printf("my name jef %d %c\n", vecOfPairs.at(0).first, vecOfPairs.at(0).second);
    if(vecOfPairs.size()>1){
      vecOfPairs.erase(vecOfPairs.begin());
    }
    
  }
  ticks++;  
  mousePosition=sf::Mouse::getPosition(window);
  robot.userInput(ticks);
  //  robotClone.automatedInput('D');
  robot.gameLoop();
  robotClone.gameLoop();
  
  if(border.collisionGameOver(robot)){
    gameOver();
  }
  border.collisionBlock(robot);
  
  for(int a=0;a<3;a++){
    infoButton[a].collision(robot);
  }
  for(int a=0;a<blockNumber;a++){
    block[a].collision(robot);
  }

  for(int a=0;a<blockNumber;a++){
    block[a].collision(robotClone);
  }

  robotClone.setSprite();
  robot.setSprite();
  scrolling();
  return render();
}

void Level_1::gameOver(){
  window.clear();
  window.draw(gameOverSprite);
  window.display();
  vecOfPairs=robot.getVector();
  // while(vecOfPairs.size()>0){
  //   cout << vecOfPairs.at(0).first << " "<< vecOfPairs.at(0).second << endl;
  //   vecOfPairs.erase(vecOfPairs.begin());
  // }
  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

  }
  robot.setPosition(0, 200, 0, 0);
}


int Level_1::render(){
  window.clear();
  window.setView(view);      
  windowTwo.clear();
  
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  window.draw(robotClone.getSprite());
  
  for(int a=0;a<3;a++){
    window.draw(infoButton[a].getSprite());
    window.draw(infoButton[a].getText(robotX));
  }

  for(int b=0;b<blockNumber;b++){
    for(int a=0;a<block[b].getNumOfSprites();a++){
      window.draw(block[b].getSprite2(a));
    }
  }
  
  mouseSprite.setPosition(mouse.getX() + robotX, mouse.getY() );
  window.draw(mouseSprite);
  printf("ticks %d", ticks );
  
  window.display();
  windowTwo.display();
}


void Level_1::scrolling(){
  robotX = robot.getX()-200;
  robotY = robot.getY();

  if(robotX<0){
    robotX=0;
  }

  backgroundSprite.setPosition(robotX, 0);
  view.reset(sf::FloatRect(robotX, 0, 800, 600));
}

void Level_1::timeLoop(){
  ticks=0;
  robot.setPosition(0, 100, 0, 0);

  vecOfPairs=robot.getVector();
  // while(vecOfPairs.size()>0){
  //   cout << vecOfPairs.at(0).first << " " << vecOfPairs.at(0).second << endl;
  //   vecOfPairs.erase(vecOfPairs.begin());
  // }
}
