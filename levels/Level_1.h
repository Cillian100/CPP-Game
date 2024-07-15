#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  int render();
  void userInput();
 private:
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;

  Robot robot;
  Block block_1;
  Block block_2;
  Block block_3;
};
