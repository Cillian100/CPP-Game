#include "Level_1.h"
#include <iostream>
using namespace std;

Level_1::Level_1(sf::RenderWindow& win) :
  window(win),
  LevelTemplate(win),
  robot(0,200,70,100),
  robotClone(200, 400, 70, 100),
  border(0, 0, 1800, 600),
  endPoint(1605, -20, 90,120)
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

  if(!font.loadFromFile("Graphics/font.ttf")){
    printf("Couldn't load font.ttf");
  }
  text.setFont(font);
  text.setCharacterSize(90);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(sf::Color::White);
  text.setString(gameWinString);

  errorText.setFont(font);
  errorText.setCharacterSize(40);
  errorText.setStyle(sf::Text::Regular);
  errorText.setFillColor(sf::Color::White);
  errorText.setString(maxNumberOfRobotsErrorMessageSting);
  
  pairKey=make_pair(696969696969, 'g');
  vecOfPairs.push_back(pairKey);
}

bool Level_1::canITimeLoopFunction(){
  printf("Hello! %d %d\n", ticks, numberOfRobotClones);
  if(ticks>50 && numberOfRobotClones>=maxNumberOfRobotClones){
    displayMaxNumberOfRobotsErrorMessage=true;
    errorMessageTicks=0;
  }  
  if(ticks>50 && numberOfRobotClones<maxNumberOfRobotClones){
    return true;
  }else{
    return false;
  }
}

int Level_1::gameLoop(){
  //printf("%d \n", ticks);
  if(nextLevel==true){
    return 2;
  }
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
    if(canITimeLoopFunction()){
      timeLoop();
    }
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
    fullReset();
  }
  
  while(vecOfPairs.at(0).first==ticks){
    //printf("%c %d\n", vecOfPairs.at(0).second, vecOfPairs.size() );
    robotClone.automatedInput(vecOfPairs.at(0).second);
    if(vecOfPairs.size()>1){
      vecOfPairs.erase(vecOfPairs.begin());
    }else{
      break;
    }    
  }
  
  ticks++;
  if(ticks>50){
    canITimeLoop=true;
  }
  
  mousePosition=sf::Mouse::getPosition(window);
  robot.userInput(ticks);
  robot.gameLoop();

  if(numberOfRobotClones>0){
    robotClone.gameLoop();
  
    for(int a=0;a<blockNumber;a++){
      block[a].collision(robotClone);
    }
    robotClone.setSprite();
    robotClone.robotOnRobotCollision(robot);
  }
  
  for(int a=0;a<3;a++){
    infoButton[a].collision(robot);
  }
  for(int a=0;a<blockNumber;a++){
    block[a].collision(robot);
  }

  if(endPoint.collision(robot)){
    gameWin();
  }

  robot.setSprite();
  templateScrolling();
  scrolling();
  render();

  return 1;
}

void Level_1::gameOver(){
  window.clear();
  gameOverSprite.setPosition(robotX, robotY);
  window.draw(gameOverSprite);
  window.display();
  //vecOfPairs.erase();
  ticks=0;
  pairKey=make_pair(696969696969, 'g');  
  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
  }
  robot.setPosition(0, 200, 0, 0);
}


int Level_1::render(){
  window.clear();
  window.setView(view);
  
  window.draw(backgroundSprite);
  window.draw(robot.getSprite());
  if(numberOfRobotClones>0){
    window.draw(robotClone.getSprite());
  }
  
  for(int a=0;a<3;a++){
   window.draw(infoButton[a].getSprite());
    window.draw(infoButton[a].getText(robotX));
  }

  for(int b=0;b<blockNumber;b++){
    for(int a=0;a<block[b].getNumOfSprites();a++){
      window.draw(block[b].getSprite2(a));
    }
  }

  if(errorMessageTicks<100 && displayMaxNumberOfRobotsErrorMessage){
    errorText.setPosition(robotX, robotY);
    window.draw(errorText);
    errorMessageTicks++;
  }

  window.draw(endPoint.getSprite());

  window.display();
}


void Level_1::scrolling(){
  robotX = robot.getX()-200;

  if(robot.getY()<100){
    robotY=robot.getY()-100;
  }else{
    robotY=0;
  }

  if(robotX<0){
    robotX=0;
  }
  if(robotX>900){
    robotX=900;
  }

  backgroundSprite.setPosition(robotX, robotY);
  view.reset(sf::FloatRect(robotX, robotY, 800, 600));
}

void Level_1::timeLoop(){
  ticks=0;
  robot.setPosition(0, 100, 0, 0);
  robotClone.setPosition(0, 200, 0, 0);
  robot.printVector();
  vecOfPairs=robot.getVector();
  cout << "important " << vecOfPairs.size() << endl;
  robot.setVecOfPairsClear();
  cout << "important2 " << vecOfPairs.size() << endl;
  numberOfRobotClones++;
  canITimeLoop=false;
}

void Level_1::fullReset(){
  ticks=0;
  robot.setPosition(0,200,0,0);
  robot.setVecOfPairsClear();
  robotClone.setPosition(0,0,0,0);
  vecOfPairs.clear();
  vecOfPairs.push_back(pairKey);  
  numberOfRobotClones=0;

  cout << "test " << endl; 
}

void Level_1::gameWin(){
  text.setPosition(robotX+20, robotY+20);
  window.draw(text);
  window.display();
  while(1){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      nextLevel=true;
      return; 
    }
  }
}
