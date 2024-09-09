#include "LevelTemplate.h"

LevelTemplate::LevelTemplate(sf::RenderWindow& win) :
  robot(0,200,70,100),
  border(0,0,0,0),
  window(win)
{
 if(!gameOverTexture.loadFromFile("Graphics/GameOverScreen.png")){
    printf("Couldn't load game over screen");
  }
  gameOverSprite.setTexture(gameOverTexture);
  gameOverSprite.setTextureRect(sf::IntRect(0,0,800,600));
  gameOverSprite.setColor(sf::Color(255,255,255,150));
  gameOverSprite.setPosition(0,0);

  clock.restart();

  if(!font.loadFromFile("Graphics/font.ttf")){
    printf("Couldn't load font.ttf");
  }
  text.setFont(font);
  text.setCharacterSize(90);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(sf::Color::White);

  pairKey=make_pair(6969696969, 'g');
  vecOfPairs.push_back(pairKey);
}

void LevelTemplate::templateLoop(){
  ticks++;
  robot.gameLoop();
  robot.userInput(ticks);
  for(int a=0;a<blockNumber;a++){
    block[a].collision(robot);
  }
  border.collisionBlock(robot);
  robot.setSprite();
}

void LevelTemplate::templateRender(){
  window.clear();
  window.setView(view);
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  for(int a=0;a<blockNumber;a++){
    for(int b=0;b<block[a].getNumOfSprites();b++){
      window.draw(block[a].getSprite2(b));
    }
  }
  //  window.display();
}

void LevelTemplate::templateScrolling(){
  robotX = robot.getX()-200;
  robotY = robot.getY()-300;

  if(robotY<0){
    robotY=0;
  }
  if(robotX<border.getX()){
    robotX=border.getX();
  }
  if(robotX>border.getX2()-800){
    robotX=border.getX2()-800;
  }

  backgroundSprite.setPosition(robotX, robotY);
  view.reset(sf::FloatRect(robotX, robotY, 800, 600));
}
