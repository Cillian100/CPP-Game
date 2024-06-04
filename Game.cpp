#include <SDL2/SDL.h>
#include "Game.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout<<"Subsystems Initialized.."<<std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

    renderer = SDL_CreateRenderer(window, -1, 0);
  }
  running=true;
}

bool Game::isRunning(){
  return running;
}

const Uint8* keystates = SDL_GetKeyboardState(NULL);

void Game::userInput(){
  dir = DEFAULT;
  if(keystates[SDL_SCANCODE_A]){
    dir = RIGHT;
  }
  if(keystates[SDL_SCANCODE_D]){
    dir = LEFT;
  }
  if(keystates[SDL_SCANCODE_W]){
    dir=UP;
  }
  if(keystates[SDL_SCANCODE_S]){
    dir=DOWN;
  }
  while(SDL_PollEvent(&e)){
    if(e.type == SDL_QUIT){
      running=false;
    }
  }
}

void Game::gameLogic(){
  switch(dir){
  case LEFT:
    head.x += 10;
    break;
  case RIGHT:
    head.x -= 10;
    break;
  case UP:
    head.y -= 10;
    break;
  case DOWN:
    head.y += 10;
    break;
  case DEFAULT:
    break;
  }
}

void Game::render(){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &head);
  SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);  
  SDL_RenderFillRect(renderer, &box);
  SDL_RenderPresent(renderer);  
}

int main(){
  Game game;
  game.init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  printf("%d \n", game.isRunning());
  while(game.isRunning()){
    game.userInput();
    game.gameLogic();
    game.render();
    SDL_Delay(25);
  }

  return 0;
}
