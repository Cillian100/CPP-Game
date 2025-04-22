#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "levels/StartingScreen.h"
#include "levels/ViewLevels.h"
#include "levels/Settings.h"
#include "levels/Level_1.h"
#include "levels/Level_2.h"
#include "levels/Level_3.h"
#include "enums/GameLevel.h"

using namespace std;

class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!", sf::Style::Default),
      startingScreen(window),
      viewLevels(window),
      settings(window),
      level_1(window),
      level_2(window),
      level_3(window)
  {    
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(61);
    setFullScreen=false;
    fullScreen=false;
  }

  void changeToFullScreen(){
      if(setFullScreen){
        window.create(sf::VideoMode(800, 600), "Platformer!", sf::Style::Fullscreen);
        fullScreen=true;
      }else{
        window.create(sf::VideoMode(800, 600), "Platformer!", sf::Style::Default);
        fullScreen=false;
      }
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
      }else if(gameLevelInteger==LEVEL_3){
      Level_3 level_3(window);
	    gameLevelInteger = level_3.gameLoop();
      }else if(gameLevelInteger==VIEW_LEVELS){
	      ViewLevels viewLevels(window);
	      gameLevelInteger = viewLevels.gameLoop();
      }else if(gameLevelInteger==SETTINGS){
	      gameLevelInteger = settings.gameLoop();
      }else if(gameLevelInteger==EXIT){
        return;
      }else if(gameLevelInteger==100){
	      gameLevelInteger = startingScreen.gameLoop();
      }else{
	      gameLevelInteger = startingScreen.gameLoop();
      }

      if(fullScreen!=setFullScreen){
        changeToFullScreen();
      }
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
  Level_3 level_3;
  int gameLevelInteger;
  bool setFullScreen;
  bool fullScreen;
  
};

int main(int argc, char *argv[]) {
  Game game;
  game.gameLoop();
  return 0;
}
