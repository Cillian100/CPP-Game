#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/InfoButton.h"
#include "../entities/Mouse.h"
#include "../entities/RobotClone.h"
#include <string>
#include <vector>
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  void gameOver();  
  int render();
  void scrolling();
  void timeLoop();
  void userInput();
 private:
  sf::Clock clock;
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Texture mouseTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::Sprite mouseSprite;
  sf::View view;
  sf::RenderWindow windowTwo;
  sf::Vector2i mousePosition;  

  Border border;
  Mouse mouse;  
  Robot robot;
  RobotClone robotClone;

  int blockNumber=6;
  int offsetHorizontal;
  int offsetVertical;
  int robotX;
  int robotY;
  int numberOfRobotClones=1;
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
    Block(1400, 100, 100, 300, 3, 2),   
    Block(1300, 100, 100, 500, 6, 1)
  };

  
};
