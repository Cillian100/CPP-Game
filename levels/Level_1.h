#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/InfoButton.h"
#include "../entities/Mouse.h"
#include <string>
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  void gameOver();  
  int render();
  void scrolling();
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

  int blockNumber=5;
  int offsetHorizontal;
  int offsetVertical;
  int robotX;
  int robotY;
  long int ticks=0;
  
  
  InfoButton infoButton[3]={
    InfoButton(10, 490, 80, 10, 0),
    InfoButton(210, 490, 80, 10, 1),
    InfoButton(1110, 490, 80, 10, 2)
  };

  Block block[5]={
    Block(0, 500, 100, 500, 5, 2),
    Block(400, 400, 200, 100, 1, 1),
    Block(800, 400, 200, 100, 1, 1),
    Block(800, 500, 100, 500, 5, 2),
    Block(1300, 200, 500, 100, 4, 1)
  };
  
};
