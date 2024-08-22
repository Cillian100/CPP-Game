#include "Level_2.h"
#include <iostream>
using namespace std;

Level_2::Level_2(sf::RenderWindow& win) :
  window(win),
  LevelTemplate(win)
{
  if(!backgroundTexture.loadFromFile("Graphics/backgroundLevel_2.jpg")){
    printf("Couldn't load level two background");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);
}

