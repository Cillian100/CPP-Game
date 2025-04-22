#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/Lazer.h"
#include "../enums/GameLevel.h"
#pragma once

class Level_2 : public LevelTemplate{
  sf::RenderWindow &window;

public:
  Lazer lazerUno;
  Level_2(sf::RenderWindow &window);
  int gameLoop();
  int render();

private:
};
