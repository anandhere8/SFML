#include <SFML/Graphics.hpp>
#include "circle.h"

 
Circle:: Circle(float x, float y, sf :: Color fillColor,
     sf :: Color outlineColor, float thickness, float radius, int id, float g, float delta_t) {
        position.x = x - radius;
        position.y = y - radius;
        velocity.x = 0;
        velocity.y = 0;
        this -> fillColor = fillColor;
        this -> outlineColor = outlineColor;      
        this -> thickness = thickness;
        this -> id = id;
        this -> radius = radius;
        gravity = g;
        this -> delta_t = delta_t;
     }

void Circle:: draw(sf :: RenderWindow& window) {
    sf:: CircleShape Circle(radius);
    Circle.setPosition(position);
    Circle.setPointCount(50);
    Circle.setFillColor(fillColor);
    Circle.setOutlineColor(outlineColor);
    Circle.setOutlineThickness(thickness);
    window.draw(Circle);
  }    

  void Circle :: print() {
    printf("Center - %f, %f\n", getCenter().x, getCenter().y);
    printf("Postion - %f, %f\n", getPosition().x, getPosition().y);
    printf("Radius - %f\n", radius);


  }

  // Getters
  sf :: Vector2f Circle::getPosition() const {
    return position;
  }

  float Circle :: getRadius() {
    return radius;
  }
  sf :: Vector2f Circle::getVelocity() const {
    return velocity;
  }

  sf :: Vector2f Circle::getCenter() {
    return sf :: Vector2f(position.x + radius, position.y + radius);
  }

  // Setters
  void Circle::setPosition(float x, float y) {
    position = sf :: Vector2f(x - radius, y - radius);
  }

  void Circle::setRadius(float r) {
    radius = r;
  }

  void Circle::setFillColor(sf :: Color color) {
    fillColor = color;
  }

  void Circle::setOutlineColor(sf :: Color color) {
    outlineColor = color;
  }

  void Circle::setThickness(float t) {
    thickness = t;
  }

  void Circle::setVelocity(float x, float y) {
    velocity = sf :: Vector2f(x, y);
  }

  void Circle :: setGravity(float g) {
    gravity = g;
  }

  
