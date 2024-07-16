#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  int render();
  void userInput();
  void gameOver();
 private:
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  

  Robot robot;
  Border border;
  Block block[9] = {
    Block(0, 500, 100, 100),
    Block(100, 500, 100, 100),
    Block(200, 500, 100, 100),
    Block(200, 400, 100, 100),
    Block(500, 500, 100, 100),
    Block(500, 400, 100, 100),
    Block(500, 300, 100, 100),
    Block(600, 500, 100, 100),
    Block(700, 500, 100, 100)
  };
};
