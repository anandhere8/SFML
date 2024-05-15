// boundary

#ifndef BOUNDARY_H
#define BOUNDARY_H


#include "SFML/Graphics.hpp"

class Boundary{
  private : 
    sf :: Vector2f center;
    float radius;
    sf :: Color color;
    int thickness;
    int length;

  public :
    
    Boundary(); // default constructor
    Boundary(float radius); // constructor with radius
    
    // setters
    void setRadius(float radius);
    void setColor(sf :: Color color);
    void setThickness(int thickness);
    void setCentre(sf :: Vector2f center);
    void setLength(int length);

    // getters
    float getRadius();
    sf :: Color getColor();
    int  getThickness();
    sf :: Vector2f getCenter();
    int getLength();


    // graphics
    void draw(sf:: RenderWindow &window);
    void drawRect(sf :: RenderWindow &window, sf :: Color &color, sf :: Vector2f &pos);

    void decreaseRadius();
};


#endif