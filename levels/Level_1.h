#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/InfoButton.h"
#include "../entities/Mouse.h"
#include "../entities/RobotClone.h"
#include "../entities/EndPoint.h"
#include <string>
#include <vector>
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  void gameOver();
  void gameWin();
  int render();
  void scrolling();
  void timeLoop();
  void fullReset();
  void userInput();
  bool canITimeLoopFunction();
 private:
  sf::Clock clock;
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Texture mouseTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::Sprite mouseSprite;
  sf::View view;
  sf::Vector2i mousePosition;
  sf::Font font;
  sf::Text text;
  sf::Text errorText;

  Border border;
  Mouse mouse;  
  Robot robot;
  RobotClone robotClone;
  EndPoint endPoint;

  bool canITimeLoop=true;
  bool nextLevel=false;
  bool displayMaxNumberOfRobotsErrorMessage=false;
  
  int blockNumber=6;
  int offsetHorizontal;
  int offsetVertical;
  int robotX;
  int robotY;
  int numberOfRobotClones=0;
  int maxNumberOfRobotClones=1;
  int errorMessageTicks=0;
  long int ticks=0;
  
  vector<pair<int, char>> vecOfPairs;
  pair<int, char> pairKey;
  
  InfoButton infoButton[3]={
    InfoButton(10, 490, 80, 10, 0),
    InfoButton(210, 490, 80, 10, 1),
    InfoButton(1110, 490, 80, 10, 2)
  };

  Block block[6]={
    Block(0, 500, 500, 100, 5, 2),
    Block(400, 400, 100, 200, 1, 1),
    Block(800, 400, 100, 200, 1, 1),
    Block(800, 500, 500, 100, 5, 2),
    Block(1400, 100, 300, 100, 3, 2),   
    Block(1300, 100, 100, 500, 6, 1)
  };

  string gameWinString="You completed Level 1.\nPress space to continue";
  string maxNumberOfRobotsErrorMessageSting="You have exceeded the allowed amount\nof robots for this level!";
};
