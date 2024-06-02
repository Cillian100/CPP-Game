#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum KeyPressSurfaces{
  KEY_PRESS_SURFACE_DEFAULT,
  KEY_PRESS_SURFACE_UP,
  KEY_PRESS_SURFACE_DOWN,
  KEY_PRESS_SURFACE_LEFT,
  KEY_PRESS_SURFACE_RIGHT,
  KEY_PRESS_SURFACE_TOTAL
};

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface(std::string path); 
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

SDL_Surface* loadSurface( std::string path){
  SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
  if(loadedSurface == NULL){
    printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  }

  return loadedSurface;
}

bool init(){
  bool success = true;

  if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
    printf("SDL could not initialize! SDL_Error: %s \n", SDL_GetError() );
    success = false;
  }else{
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(gWindow == NULL){
      printf("Window could not be created! SLD_Error %s \n", SDL_GetError() );
      success = false;
    }else{
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }

  return success;
}

bool loadMedia(){
  bool success = true;
  gHelloWorld = SDL_LoadBMP("preview.bmp");
  if(gHelloWorld == NULL){
    printf("Unable to load image %s! SDL_Error %s", "preview.bmp", SDL_GetError() );
    success = false;
  }

  return success;
}

void close(){
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld = NULL;

  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  SDL_Quit();
}

int main( int argc, char* args[] ){
  //The window we'll be rendering to
  SDL_Window* window = NULL;
  //The surface contained by the window
  SDL_Surface* screenSurface = NULL;
  bool quit = false;
  SDL_Event e;

  if(!init()){
    printf("Failed to initialize\n");
  }else{
    if(!loadMedia()){
      printf("Failed to load media!\n");
    }else{
      while(!quit){
	while(SDL_PollEvent(&e) != 0){
	  if(e.type == SDL_QUIT){
	    quit=true;
	  }
	}
      }
      SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
      SDL_UpdateWindowSurface(gWindow);
      SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }      
    }
  }

  close();
  
  return 0;
}
