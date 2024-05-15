#include "SFML/Graphics.hpp"
#include "boundary.h"
#include "ball.h"
#include "circle.h"
#include "util.h"

const int FPS = 60,
          screen_w = 600,
          screen_h = 800;          

int main() {

  sf :: Vector2f center = sf :: Vector2f(screen_w / 2, screen_h / 2);
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(screen_w, screen_h), "Ball Simulation", 
  sf::Style::Default, settings);
  window.setFramerateLimit(FPS);
  
  Boundary wall;
  wall.setCentre(center);
  wall.setLength(screen_h);
  wall.setRadius(screen_w / 2);

  std :: vector<Ball> balls(7);
  int i = 0;
  for (auto &ball : balls) {
    ball.setRadius(15);
    ball.setFillColor(sf ::Color :: Red);
    ball.setPosition(screen_w/2 + 1.2f * i , screen_h/1.5f - 1.5f*i);
    ball.setID(i / 10);
    i += 30;
  }

  while(window.isOpen()){
    window.clear(sf :: Color :: Black);
    sf :: Event event;
    while (window.pollEvent(event)) {
      if (event.type == event.Closed) {
        window.close();
      }
    }
    for (auto &ball : balls) {
      ball.motion();
      ball.increaseRadius();
      if (IsCollision(ball, wall, center)) {
        printf("YES there is collisoin\n");
        while(IsCollision(ball, wall, center)) {
          ball.reverse();
        }
        handleCollision(ball, wall);
      }
      
      wall.draw(window);
      ball.draw(window);
      
    }
    wall.decreaseRadius();
    window.display();
  }
  return 0;
}