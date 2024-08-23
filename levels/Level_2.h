#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#pragma once

class Level_2 : public LevelTemplate{
  sf::RenderWindow& window;
 public:
  Level_2(sf::RenderWindow& win);
  int gameLoop();
  int render();  
 private:
};
