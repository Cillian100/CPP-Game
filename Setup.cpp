#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "triangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!"),
      cir(100, 100, 100),
      mouse(0, 0, 100),
      squ(0, 0, 800, 600){
    shape.setRadius(cir.getRadius());
    shape.setPosition(cir.getX(), cir.getY());
    shape.setFillColor(sf::Color::Green);

    cursor.setRadius(mouse.getRadius());
    cursor.setPosition(mouse.getX(), mouse.getY());
    cursor.setFillColor(sf::Color::Blue);

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
      
      mouseFunction();
      calculate();
      render();
      collision();
    }
  }

private:
  void mouseFunction(){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    mouse.setX(position.x - mouse.getRadius());
    mouse.setY(position.y - mouse.getRadius());
    cursor.setPosition(mouse.getX(), mouse.getY());

    if(event.type == sf::Event::MouseButtonPressed){
      mousePressed=true;
    }else{
      mousePressed=false;
    }
    
  }
  
  void render() {
    string fpsOutput = "fps " + to_string((int)fps);
    
    text.setString(fpsOutput);    
    window.clear();
    window.draw(text);
    window.draw(shape);
    if(mousePressed){
      cursor.setFillColor(sf::Color::Blue);
    }else{
      cursor.setFillColor(sf::Color::Red);
    }
    window.draw(cursor);
    window.display();
    
  }

  void calculate(){
    cir.setX(cir.getX() + 1);
    cir.setY(cir.getY() + 1);
    shape.setPosition(cir.getX(), cir.getY());
  }

  void collision(){
  }

  sf::RenderWindow window;
  sf::CircleShape shape;
  sf::CircleShape cursor;
  sf::RectangleShape box;
  sf::Event event;
  sf::Font font;
  sf::Text text;
  float fps;
  bool mousePressed;
  circle cir;
  circle mouse;
  square squ;
};

int main() {
  Game game;
  triangle tri(10, 20);
  game.gameLoop();

  return 0;
}
