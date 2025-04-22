#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../enums/GameLevel.h"
#pragma once

class Level_1 : public LevelTemplate{
    sf::RenderWindow& window;
public:
    Level_1(sf::RenderWindow &window);
    int gameLoop();
    int render();
};