#include <SDL2/SDL.h>
#include "Game.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
  verticleVelocity=0;
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout<<"Subsystems Initialized.."<<std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

    renderer = SDL_CreateRenderer(window, -1, 0);
  }
  running=true;
  collision=false;
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
    jump=true;
  }else{
    jump=false;
  }
  if(keystates[SDL_SCANCODE_LSHIFT]){
    shift=true;
  }else{
    shift=false;
  }
  while(SDL_PollEvent(&e)){
    if(e.type == SDL_QUIT){
      running=false;
    }
  }
}

void Game::squaresquare(){
  collision=false;
  
  int R1rightEdge=head.x;
  int R1leftEdge=head.w+R1rightEdge;

  int R2rightEdge=box.x;
  int R2leftEdge=box.w+R2rightEdge;

  int R1topEdge=head.y;
  int R1bottomEdge=head.h+R1topEdge;

  int R2topEdge=box.y;
  int R2bottomEdge=box.h+R2topEdge;

  if( (R1rightEdge<R2leftEdge) && (R1leftEdge>R2rightEdge) && (R1bottomEdge>R2topEdge) && (R1topEdge<R2bottomEdge) ){
    if( (R1bottomEdge-R2topEdge) > (R2bottomEdge-R1topEdge) ){
      head.y=head.y+(R2bottomEdge-R1topEdge);
    }else{
      head.y=head.y-(R1bottomEdge-R2topEdge);
    } 
    collision=true;
  }


  
}  


void Game::gameLogic(){
  if(verticleVelocity<100){
    verticleVelocity++;    
  }
  head.y += verticleVelocity/20;
  int move;
  if(shift){
    move=1;
  }else{
    move=5;
  }
  switch(dir){
  case LEFT:
    head.x += move;
    break;
  case RIGHT:
    head.x -= move;
    break;
  case DEFAULT:
    break;
  }

  if(jump==true){
    if(collision==true){
      verticleVelocity=-100;
    }
  }else{
  }
  
}

void Game::render(){
  printf("velocity %d \n", verticleVelocity);
  
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  if(collision){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  }else{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
  }
  SDL_RenderFillRect(renderer, &box);
  SDL_RenderFillRect(renderer, &box2);
  
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &head);
  
  SDL_RenderPresent(renderer);
  
}

int main(){
  Game game;
  game.init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  printf("%d \n", game.isRunning());

  while(game.isRunning()){
    game.userInput();
    game.gameLogic();
    game.squaresquare();
    game.render();
    SDL_Delay(10);
  }

  return 0;
}
