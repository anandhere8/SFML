// circle

#ifndef CIRCLE_H
#define CIRCLE_H

#include<SFML/Graphics.hpp>
#include <vector>

class Circle{
private :
  int id;
  sf :: Vector2f position;
  sf :: Vector2f center;
  sf :: Vector2f initialPosition;
  float radius;
  sf :: Color fillColor;
  sf :: Color outlineColor;
  sf :: Vector2f velocity;
  
  

protected : 
  float gravity;
  float delta_t;
  float thickness;
  std :: vector<sf::Vector2f> positionVector;
  std :: vector<sf::Vector2f> trails;
  int trailHead = 0;

public: 
  Circle(float x = 0, float y = 0, 
         sf::Color fillColor = sf::Color::Transparent,
         sf::Color outlineColor = sf::Color::White, 
         float thickness = 1, 
         float radius = 100, 
         int id = 2, float g = 0, float delta_t = 0.01);

  Circle(float radius, sf :: Color color);
  void draw(sf :: RenderWindow& window);
  void draw(sf :: RenderTexture& texture);
  void draw(sf :: RenderWindow& window, sf :: RenderTexture& texture);
  void print();

  // Getters
  sf :: Vector2f getPosition() const;

  sf :: Vector2f getVelocity() const;
  sf :: Vector2f getCenter() ;

  float getRadius();

  // Setters
  void setPosition(float x, float y) ;

  void setInitialPosition(float x, float y);

  void setRadius(float r) ;

  void setFillColor(sf :: Color color) ;

  void setOutlineColor(sf :: Color color) ;
  void setThickness(float t) ;

  void setVelocity(float x, float y);
  void setGravity(float g);


  void updateTrail(sf:: Vector2f position);

  void setID(int id);

  // Getters

  int getID();
};

#endif 