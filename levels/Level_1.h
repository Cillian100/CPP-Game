#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#pragma once

class Level_1{
  sf::RenderWindow& window;
 public:
  Level_1(sf::RenderWindow& win);
  int gameLoop();
  int render();
 private:
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;

  Robot robot;
};
