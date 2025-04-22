#include "LevelTemplate.h"

LevelTemplate::LevelTemplate(sf::RenderWindow& win) :
  robot(0,200,70,100),
  border(0,0,0,0),
  endPoint(0, 0, 0, 0),
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

  errorText.setFont(font);
  errorText.setCharacterSize(50);
  errorText.setStyle(sf::Text::Regular);
  errorText.setFillColor(sf::Color::White);
  errorText.setString(maxNumberOfRobotsErrorMessageString);

  pairKey=make_pair(6969696969, 'g');
  vecOfPairs.push_back(pairKey);
}

void LevelTemplate::resetEverything(){
  robot.setPosition(0,200,0,0);
}

int LevelTemplate::exitToStartingScreen(){
  resetEverything();
  return 100;
}

int LevelTemplate::templateLoop(){
  while(vecOfPairs.at(0).first==ticks){
    robotClone[0].automatedInput(vecOfPairs.at(0).second);
    if(vecOfPairs.size()>1){
      vecOfPairs.erase(vecOfPairs.begin());
    }else{
      break;
    }
  }

  ticks++;
  robot.gameLoop();
  robotClone[0].gameLoop();
  robot.userInput(ticks);
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
    if(canITimeLoopFunction()){
      timeLoop();
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
    fullResetTemplate();
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    return exitToStartingScreen();
  }
  
  for(int a=0;a<blockNumber;a++){
    block[a].collision(robot);
    block[a].collision(robotClone[0]);
  }
  border.collisionBlock(robot);
  border.collisionBlock(robotClone[0]);
  
  if(numberOfRobotClones>0){
    robotClone[0].robotOnRobotCollision(robot);
  }
  
  if( endPoint.collision(robot) ){
    return gameWin();
  }

  if( robot.getDieOrNot() == true){
    return gameLose();
  }
  
  robot.setSprite();
  robotClone[0].setSprite();
  
  return currentLevel;
}

void LevelTemplate::timeLoop(){
  numberOfRobotClones++;
  robotClone[0].setPosition(0,200,0,0);
  robot.setPosition(0,100,0,0);
  if(vecOfPairs.size()<10){
    vecOfPairs=robot.getVector();
  }
  robot.setVecOfPairsClear();
  ticks=0;
}

bool LevelTemplate::canITimeLoopFunction(){
  if(ticks>50 && numberOfRobotClones>=maxNumberOfRobotClones){
    displayMaxNumberOfRobotClones=true;
    errorMessageTicks=0;
  }
  
  if(ticks>50 && numberOfRobotClones<maxNumberOfRobotClones){
    return true;
  }else{
    return false;
  }
}

void LevelTemplate::fullResetTemplate(){
  numberOfRobotClones=0;
  robot.setPosition(0,200,0,0);
  robot.setVecOfPairsClear();
  ticks=0;
}

int LevelTemplate::gameWin(){
  text.setString(youWon1 + to_string(currentLevel) + youWon2);
  text.setPosition(view.getCenter().x-380, view.getCenter().y-280);
  window.draw(text);
  window.display();
  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    
  }
  return currentLevel+1;
}

int LevelTemplate::gameLose(){
  text.setCharacterSize(70);
  text.setString(youDied);
  text.setPosition(view.getCenter().x-380, view.getCenter().y-280);
  window.draw(text);
  window.display();
  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      text.setCharacterSize(90);
      if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        robot.setDie(false);
        fullResetTemplate();
      }
  }
  return currentLevel;
}

void LevelTemplate::templateRender(){
  window.clear();
  window.setView(view);
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  if(numberOfRobotClones>0){
    window.draw(robotClone[0].getSprite());
  }
  
  window.draw(endPoint.getSprite());
  for(int a=0;a<blockNumber;a++){
    for(int b=0;b<block[a].getNumOfSprites();b++){
      window.draw(block[a].getSprite2(b));
    }
  }

  for(int a=0;a<numberOfInfoButtons;a++){
    window.draw(infoButton[a].getSprite());
  }

  for(int a=0;a<numberOfLazer;a++){
    for(int b=0;b<lazer[a].getNumberOfSprites();b++){
      window.draw(lazer[a].getSpriteDos(b));
    }
  }
  
  if(errorMessageTicks<100 && displayMaxNumberOfRobotClones){
    errorText.setPosition(robotX, robotY);
    window.draw(errorText);
    errorMessageTicks++;
  }
}

void LevelTemplate::templateScrolling(){
  robotX = robot.getX()-200;
  robotY = robot.getY()-300;

  printf("%d %d\n", robotY, border.getY());

  if(robotY<border.getY()){
    robotY=border.getY();
  }

  if(robotX<border.getX()){
    robotX=border.getX();
  }
  if(robotX>border.getX2()-800){
    robotX=border.getX2()-800;
  }  

  if(robotY>border.getY2()){
    robotY=border.getY2();
  }

  backgroundSprite.setPosition(robotX, robotY);
  view.reset(sf::FloatRect(robotX, robotY, 800, 600));
}
