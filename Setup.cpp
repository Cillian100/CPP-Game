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
      player(100, 100, 100, 100),
      squ(0, 0, 800, 600){
    shape.setRadius(cir.getRadius());
    shape.setPosition(cir.getX(), cir.getY());
    shape.setFillColor(sf::Color::Green);

    cursor.setRadius(mouse.getRadius());
    cursor.setPosition(mouse.getX(), mouse.getY());
    cursor.setFillColor(sf::Color::Blue);

    playerSF.setSize(sf::Vector2f(player.getWidth(), player.getLength()));
    playerSF.setPosition(player.getX(), player.getY());
    playerSF.setFillColor(sf::Color::Red);

    box.setSize(sf::Vector2f(800,600));
    box.setPosition(squ.getX(), squ.getY());
    box.setFillColor(sf::Color::Red);

    window.setMouseCursorVisible(false);
    window.setFramerateLimit(61);

    if(!font.loadFromFile("gothic.ttf")){
      printf("Error!! \n");
    }

    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular); 
    text.setFillColor(sf::Color::Green);
    text.setPosition(0, 560);    
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      cout << "left" << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      cout << "right" << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
      cout << "jump" << endl;
    }
  }

  void playerLogic(){
    player.setVelocityY(player.getVelocityY() + 0.3);
    cout << "velocity " << player.getVelocityY() << endl;
    player.setY(player.getY() + player.getVelocityY());

    if(collision.squareInsideSquare(player, squ)){
      if(player.getY2()>=squ.getY2()){
	player.setY(squ.getY2() - player.getWidth());
	player.setVelocityY(-10);
      }
    }
  }

  void render() {
    string fpsOutput = "fps " + to_string((int)fps);
    
    text.setString(fpsOutput);    
    window.clear();
    window.draw(text);
    //window.draw(shape);
    if(mouseBorderCollision){
      cursor.setFillColor(sf::Color::Blue);
    }else{
      cursor.setFillColor(sf::Color::Red);
    }
    //window.draw(cursor);
    playerSF.setPosition(player.getX(), player.getY());
    window.draw(playerSF);
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
  sf::Event event;
  sf::Font font;
  sf::Text text;
  sf::RectangleShape playerSF;
  float fps;
  bool mousePressed;
  bool mouseBorderCollision;
  circle cir;
  circle mouse;
  square player;
  square squ;
  Collision collision;
};

int main() {
  Game game;
  triangle tri(10, 20);
  game.gameLoop();

  return 0;
}
