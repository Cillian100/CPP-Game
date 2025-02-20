#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/RobotClone.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/EndPoint.h"
#include "../entities/InfoButton.h"
#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

class LevelTemplate{
  sf::RenderWindow& window;
 public:
  LevelTemplate(sf::RenderWindow& win);
  bool canITimeLoopFunction();
  int templateLoop();
  int exitToStartingScreen();
  int gameLose();
  int gameWin();
  void templateRender();
  void templateScrolling();
  void fullResetTemplate();
  void timeLoop();
  void resetEverything();  
  sf::Clock clock;  
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::Font font;
  sf::Text text;
  sf::Text errorText;
  sf::View view;
  bool displayMaxNumberOfRobotClones;
  vector<pair<int, char>> vecOfPairs;
  pair<int, char> pairKey;
  string youWon1="You completed level ";
  string youWon2="\nPress space to continue";
  string youDied="Ouch! Your poor robot has died!\n Press space to start again";
  string maxNumberOfRobotsErrorMessageString="You have exceeded the allowed amount\nof robots for this level!";  
  int currentLevel;
  int numberOfRobotClones=0;
  int numberOfInfoButtons=0;
  int maxNumberOfRobotClones;
  int errorMessageTicks;
  long int ticks=0;
  int robotX;
  int robotY;
  int blockNumber=0;
  Robot robot;
  RobotClone robotClone[2]={
    RobotClone(0, 0, 70, 100),
    RobotClone(0, 0, 70, 100)
  };
  Block block[7]={
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0)
  };
  
  InfoButton infoButton[3]={
    InfoButton(0,0,0,0,0),
    InfoButton(0,0,0,0,0),
    InfoButton(0,0,0,0,0)
  };

  Border border;
  EndPoint endPoint;
  
 private:
};
