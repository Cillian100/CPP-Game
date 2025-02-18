#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/Lazer.h"
#pragma once

class Level_2 : public LevelTemplate{
  sf::RenderWindow& window;
 public:
  Lazer lazerUno;
  Level_2(sf::RenderWindow& win);
  int gameLoop();
  int render();  
 private:
};
