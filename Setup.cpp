#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "triangle.h"
#include "circle.h"
#include "square.h"
#include "Collision.h";

using namespace std;

class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!"),
      cir(100, 100, 100),
      mouse(0, 0, 50),
      player(0, 0, 70, 100),
      object(0, 450, 200, 100),
      squ(0, 0, 800, 600),
      floor(0, 550, 800, 50){
    rectShapeFloor.setSize(sf::Vector2f(floor.getWidth(), floor.getHeight()));
    rectShapeFloor.setPosition(floor.getX(), floor.getY());
    rectShapeFloor.setFillColor(sf::Color::Red);
    
    playerSF.setSize(sf::Vector2f(player.getWidth(), player.getHeight()));
    playerSF.setPosition(player.getX(), player.getY());
    playerSF.setFillColor(sf::Color::Red);
    
    platform.setSize(sf::Vector2f(object.getWidth(),object.getHeight()));
    platform.setPosition(object.getX(), object.getY());
    platform.setFillColor(sf::Color::Red);

    window.setMouseCursorVisible(false);
    window.setFramerateLimit(61);

    if(!font.loadFromFile("gothic.ttf")){
      printf("Couldn't load gothic.ttf! \n");
    }

    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular); 
    text.setFillColor(sf::Color::Green);
    text.setPosition(0, 560);

    if(!texture.loadFromFile("Graphics/robot.png")){
      printf("Couldn't load robot.png! \n");
    }
    
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,70,100));
    sprite.setColor(sf::Color(255,255,255,255));

    backgroundTexture.loadFromFile("Graphics/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,800,800));
    backgroundSprite.setColor(sf::Color(255,255,255,255));
    backgroundSprite.setPosition(0,0);
  }

  void gameLoop() {
    sf::Time t1 = sf::milliseconds(10);
    sf::Clock clock;
    
    while (window.isOpen()) {
      float currentTime = clock.restart().asSeconds();
      fps = 1.0f/(currentTime);
      
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }
      
      playerMovement();
      playerLogic();
      mouseFunction();
      calculate();
      render();
    }
  }
  
private:
  void mouseFunction(){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    mouse.setX(position.x - mouse.getRadius());
    mouse.setY(position.y - mouse.getRadius());

    if(event.type == sf::Event::MouseButtonPressed){
      mousePressed=true;
    }else{
      mousePressed=false;
    }
  }

  void playerMovement(){
    playerUp = DEFAULT;
    playerHorizontal = HORIZONTAL_DEFAULT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      playerHorizontal = LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      playerHorizontal = RIGHT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
      playerUp = JUMP;
    }
  }

  void playerLogic(){
    if(player.getVelocityY()>0){
      player.setVelocityY(player.getVelocityY() + 0.4);
    }else{
      player.setVelocityY(player.getVelocityY() + 0.3);
    }

    if(playerHorizontal==RIGHT){
      player.setX(player.getX() + 7);
    }
    if(playerHorizontal==LEFT){
      player.setX(player.getX() - 7);
    }

    if(collision.squarePlatform(player, floor)){
      if(playerUp == JUMP){
	player.setVelocityY(-10);
      }else{
	player.setVelocityY(1);
      }
	 
    }

    // if(collision.squareInsideSquare(player, squ)){
    //   if(playerUp == JUMP){
    // 	player.setVelocityY(-10);
    //   }else{
    // 	player.setVelocityY(1);
    //   }
    //   if(player.getY2()>=squ.getY2()){
    //    	player.setY(squ.getY2() - player.getHeight());
    //   }
    // }

    // collision.squareOutsideSquare(player, object);
    
    player.setY(player.getY() + player.getVelocityY());
    player.setX(player.getX() + player.getVelocityX());
  }

  void render() {
    string fpsOutput = "fps " + to_string((int)fps);
    text.setString(fpsOutput);
    
    window.clear();
    window.draw(backgroundSprite);
    window.draw(text);

    if(mouseBorderCollision){
      cursor.setFillColor(sf::Color::Blue);
    }else{
      cursor.setFillColor(sf::Color::Red);
    }

    sprite.setPosition(player.getX(),player.getY());
    window.draw(sprite);
    //window.draw(platform);
    window.draw(rectShapeFloor);
    window.display();
    
  }

  void calculate(){
    cir.setX(cir.getX() + 1);
    cir.setY(cir.getY() + 1);
    shape.setPosition(cir.getX(), cir.getY());

    mouseBorderCollision=collision.circleInsideSquare(mouse, squ);

    if(!mouseBorderCollision){
      if(mouse.getX()<squ.getX()){
	mouse.setX(squ.getX());
      }
      if(mouse.getX()+(mouse.getRadius()*2)>squ.getX2()){
	mouse.setX(squ.getX2()-(mouse.getRadius()*2));
      }
      if(mouse.getY()<squ.getX()){
	mouse.setY(squ.getY());
      }
      if(mouse.getY()+(mouse.getRadius()*2)>squ.getY2()){
	mouse.setY(squ.getY2()-(mouse.getRadius()*2));
      }
    }

    cursor.setPosition(mouse.getX(), mouse.getY());
  }
  
  sf::RenderWindow window;
  sf::CircleShape shape;
  sf::CircleShape cursor;
  sf::RectangleShape box;
  sf::RectangleShape platform;
  sf::Event event;
  sf::Font font;
  sf::Text text;
  sf::RectangleShape playerSF;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;
  sf::RectangleShape rectShapeFloor;
  
  float fps;
  bool mousePressed;
  bool mouseBorderCollision;
  circle cir;
  circle mouse;
  square player;
  square squ;
  square object;
  square floor;
  
  Collision collision;
  int playerUp;
  int playerHorizontal;

  enum playerUpEnum{
    JUMP,
    DEFAULT
  };

  enum playerHorizontalEnum{
    RIGHT,
    LEFT,
    HORIZONTAL_DEFAULT
  };
};

int main() {
  Game game;
  triangle tri(10, 20);
  game.gameLoop();

  return 0;
}
