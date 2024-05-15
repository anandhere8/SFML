#include "boundary.h"
#include "SFML/Graphics.hpp"

Boundary :: Boundary() {
  thickness = 5;
  color = sf :: Color :: Magenta;
  center = sf :: Vector2f(100, 100);
  radius = 10;
}


// setters
void Boundary :: setCentre(sf :: Vector2f center) {
  this->center = center;
}

void Boundary :: setColor(sf :: Color color) {
  this -> color = color;
}

void Boundary :: setRadius(float radius) {
  this -> radius = radius;
}

void Boundary :: setThickness(int thickness) {
  this -> thickness = thickness;
}

void Boundary :: setLength(int length) {
  this -> length = length;
}

// getters

int Boundary :: getThickness() {
  return this -> thickness;
}

float Boundary :: getRadius() {
  return radius;
}

sf :: Color Boundary :: getColor() {
  return color;
}

sf :: Vector2f Boundary :: getCenter() {
  return center;
}

int Boundary :: getLength() {
  return length;
}

void Boundary :: decreaseRadius() {
  float radius = getRadius();
  if (radius < 20) radius = 20;
  setRadius(radius - 0.2);
}


void Boundary :: drawRect(sf :: RenderWindow &window, sf :: Color &color, sf :: Vector2f &pos) {
  sf :: RectangleShape rect;
  rect.setFillColor(color);
  rect.setPosition(pos);
  rect.setOutlineThickness(1);
  rect.setSize(sf :: Vector2f(20, length));
  window.draw(rect);
}


void Boundary :: draw(sf :: RenderWindow &window) {
  // left rectanlge;
  sf :: Vector2f leftPos = center - sf :: Vector2f(radius, 0);
  leftPos.y -= length / 2;
  
  drawRect(window, color, leftPos);

  // right rectangle
  sf :: Vector2f rightPos = center + sf :: Vector2f(radius - 20, 0);
  rightPos.y -= length / 2;
  drawRect(window, color, rightPos);
}

