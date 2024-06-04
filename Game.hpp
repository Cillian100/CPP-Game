#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>

class Box{
public:
  int x;
  int y;
  int height;
  int width;
  Box(int a, int b, int c, int d){
    x = a;
    y = b;
    height = c;
    width = d;
  }
};
  
class Game{
public:
  void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
  void render();
  void userInput();
  void gameLogic();
  bool isRunning();
private:
  SDL_Event e;
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;
  SDL_Rect head {500, 500, 10, 10};
  SDL_Rect box {0, 500, 800, 100};
  int dir;
  
  enum Direction{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DEFAULT
  };
};
#endif
