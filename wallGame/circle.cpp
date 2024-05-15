#include <SFML/Graphics.hpp>
#include "circle.h"

 
Circle:: Circle(float x, float y, sf :: Color fillColor,
     sf :: Color outlineColor, float thickness, float radius, int id, float g, float delta_t) {
        position.x = x - radius;
        position.y = y - radius;
        velocity.x = 100;
        velocity.y = 0;
        this -> fillColor = fillColor;
        this -> outlineColor = outlineColor;      
        this -> thickness = thickness;
        this -> id = id;
        this -> radius = radius;
        gravity = g;
        this -> delta_t = delta_t;
        trailHead = -1;
     }

Circle :: Circle(float radius, sf :: Color color) {
  this->radius = radius;
  this-> fillColor = color;
  position.x = 100 - radius;
  position.y = 100 - radius;
}

    void Circle:: draw(sf :: RenderWindow& window) {
      sf:: CircleShape Circle(radius);    
      Circle.setPosition(position);
      Circle.setPointCount(50);
      Circle.setFillColor(fillColor);
      Circle.setOutlineColor(outlineColor);
      Circle.setOutlineThickness(thickness);
          
      window.draw(Circle);

      sf::VertexArray vertexArray(sf::Points);
      
      if ((int)trails.size() > 2) {
        
        int l = trailHead - 1;
        int r = trailHead;
        int count = 0;
        while (l != trailHead) {
          if (trailHead < l) {
            if (l - trailHead < 4) break;
          }
          count++;
          if (count > 1500) break;
          if (l < 0) {
            l = (int)trails.size() - 1;
          } 
          if (r < 0) {
            r = (int)trails.size() - 1;
          }
          sf::Vertex line[] = {
              sf::Vertex(trails[r]),
              sf::Vertex(trails[l])
          };
          float opacityFactor = static_cast<float>((int)trails.size() - count) / (int)trails.size() * 1.0f;
          sf::Uint8 newAlpha = static_cast<sf::Uint8>(fillColor.a * opacityFactor);

        // Create a new color with less opacity based on ballColor
          sf::Color lessOpaqueColor = fillColor;
          lessOpaqueColor.a = newAlpha;
          line[0].color = lessOpaqueColor;
          line[1].color = lessOpaqueColor;

          vertexArray.append(sf :: Vertex(trails[l], lessOpaqueColor));
          // window.draw(line, 2, sf::Lines);
          l--, r--;
        }
        window.draw(vertexArray);
      }
    } 

  void Circle:: draw(sf :: RenderTexture& window) {
    sf:: CircleShape Circle(radius);    
    Circle.setPosition(position);
    Circle.setPointCount(50);
    Circle.setFillColor(fillColor);
    Circle.setOutlineColor(outlineColor);
    Circle.setOutlineThickness(thickness);
        
    window.draw(Circle);
    
    if ((int)trails.size() > 5) {
      
      int l = trailHead - 1;
      int r = trailHead;
      int count = 0;
      while (l != trailHead) {
        count++;
        if (count > 1500) break;
        if (l < 0) {
          l = (int)trails.size() - 1;
        }
        if (r < 0) {
          r = (int)trails.size() - 1;
        }
        sf::Vertex line[] = {
            sf::Vertex(trails[r]),
            sf::Vertex(trails[l])
        };
        line[0].color = fillColor;
        line[1].color = fillColor;
        window.draw(line, 2, sf::Lines);
        l--, r--;
      }
    }
  }    

  void Circle:: draw(sf :: RenderWindow &window, sf :: RenderTexture& texture) {
    sf:: CircleShape Circle(radius);    
    Circle.setPosition(position);
    Circle.setPointCount(50);
    Circle.setFillColor(fillColor);
    Circle.setOutlineColor(outlineColor);
    Circle.setOutlineThickness(thickness);
    sf :: VertexArray line(sf :: Lines, 2);
    sf :: VertexArray points(sf :: Points);
    points.append(getCenter());
    line[0].position = initialPosition;
    line[1].position = getCenter();
    line[0].color    = fillColor;
    line[1].color    = fillColor; 
    
    // velocity = sf :: Vector2f(25, 5);
    
    texture.draw(line);
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
    setInitialPosition(getCenter().x, getCenter().y);
    position = sf :: Vector2f(x - radius, y - radius);   
    // printf("x - %f, y - %f\n", position.x, position.y); 
    updateTrail(sf :: Vector2f(x, y));
  }

  void Circle::setRadius(float r) {
    if (r < 0.5) return;
    
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
    if (x > 200) x = 200;
    // if (y > 100) y = 100;
    velocity = sf :: Vector2f(x, y);
  }

  void Circle :: setGravity(float g) {
    gravity = g;
  }

  void Circle :: setInitialPosition(float x, float y) {
    initialPosition = sf :: Vector2f(x, y);
    // updateTrail(initialPosition);
  }

  void Circle :: updateTrail(sf :: Vector2f position) {
    int len = 50;
    trailHead++;
    trailHead %= len;
    if (trailHead == (int)trails.size()) {
      trails.push_back(position);
      
    } else {
      trails[trailHead] = position;
    }
  }

  


  void Circle:: setID(int id) {
    this -> id = id;
  }

  // Getters

  int Circle :: getID() {
    return id;
  }