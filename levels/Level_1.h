#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/InfoButton.h"
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
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::View view;
  sf::RenderWindow windowTwo;
  sf::Vector2i mousePosition;  

  Border border;
  Robot robot;

  int blockNumber=18;
  
  InfoButton infoButton[2] = {
    InfoButton(10, 490, 80, 10, 0),
    InfoButton(210, 490, 80, 10, 1)
  };

  Block block[18] = {
    Block(0, 500, 100, 100),
    Block(100, 500, 100, 100),
    Block(200, 500, 100, 100),
    Block(300, 500, 100, 100),
    Block(300, 400, 100, 100),
    Block(600, 500, 100, 100),
    Block(600, 400, 100, 100),
    Block(600, 300, 100, 100),
    Block(700, 500, 100, 100),
    Block(800, 500, 100, 100),
    Block(900, 500, 100, 100),
    Block(1000, 500, 100, 100),
    Block(1100, 500, 100, 100),
    Block(1200, 500, 100, 100),
    Block(1200, 400, 100, 100),
    Block(1200, 300, 100, 100),
    Block(1200, 200, 100, 100),
    Block(1200, 100, 100, 100)
  };
};
