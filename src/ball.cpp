#include <SFML/Graphics.hpp>
#include "ball.h"
#include "circle.h"

void Ball::motion(int reverse) {
  auto velocity = getVelocity();
  auto center   = getCenter();

  velocity.y    += gravity *  delta_t * reverse;
  setVelocity(velocity.x, velocity.y);
  center.x     += velocity.x * delta_t * reverse;
  center.y     += (velocity.y * delta_t + 0.5f * gravity * delta_t * delta_t) * reverse;
  setPosition(center.x, center.y);
  setThickness();
}

void Ball :: setThickness() {
  thickness = 2;
}

void Ball :: increaseRadius() {
  float radius = getRadius();
  // radius += 1;
  setRadius(radius);  
  auto velocity = getVelocity();
  // velocity += sf :: Vector2f(5, 5);
  setVelocity(velocity.x + 100, velocity.y);
}
