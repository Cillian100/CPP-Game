#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "levels/StartingScreen.h"
#include "levels/ViewLevels.h"
#include "levels/Settings.h"
#include "levels/Level_1.h"
#include "levels/Level_2.h"

using namespace std;

class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!"),
      startingScreen(window),
      viewLevels(window),
      settings(window),
      level_1(window),
      level_2(window)
  {    
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(61);
  }

  void gameLoop() {
    sf::Time t1 = sf::milliseconds(10);
    sf::Clock clock;
    gameLevelInteger=STARTING_SCREEN;
    
    while (window.isOpen()) {
      float currentTime = clock.restart().asSeconds();
      fps = 1.0f/(currentTime);
      
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }

      if(gameLevelInteger==STARTING_SCREEN){
	gameLevelInteger = startingScreen.gameLoop();
      }else if(gameLevelInteger==LEVEL_1){
	gameLevelInteger = level_1.gameLoop();
      }else if(gameLevelInteger==LEVEL_2){
       	gameLevelInteger = level_2.gameLoop();
      }else if(gameLevelInteger==10){
	gameLevelInteger = viewLevels.gameLoop();
      }else if(gameLevelInteger==11){
	gameLevelInteger = settings.gameLoop();
      }else{
	gameLevelInteger = startingScreen.gameLoop();
      }
      printf("%d \n", gameLevelInteger);
      
    } 
  }
  
private:  
  sf::RenderWindow window;
  sf::Event event;
  
  float fps;
  StartingScreen startingScreen;
  ViewLevels viewLevels;
  Settings settings;
  Level_1 level_1;
  Level_2 level_2;
  int gameLevelInteger;

  enum gameLevel{
    STARTING_SCREEN,
    LEVEL_1,
    LEVEL_2
  };
  
};

int main(int argc, char *argv[]) {
  Game game;
  game.gameLoop();
  return 0;
}
