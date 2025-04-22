#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"
#include "../enums/GameLevel.h"
 
class Level_3 : public LevelTemplate{
  sf::RenderWindow& window;
 public:
  Level_3(sf::RenderWindow& window);
  ~Level_3();
  int gameLoop();

  
 private:
};
