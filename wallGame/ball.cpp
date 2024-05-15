#include <SFML/Graphics.hpp>
#include "ball.h"
#include "circle.h"

void Ball::motion(int reverse) {
  auto velocity = getVelocity();
  auto center   = getCenter();

  velocity.y    += gravity *  delta_t * reverse;
  int id = getID();
  setVelocity(velocity.x, velocity.y);
  center.x     += velocity.x * delta_t * reverse;
  center.y     += (velocity.y * delta_t + 0.5f * gravity * delta_t * delta_t) * reverse;
  setPosition(center.x, center.y);
  // setThickness();
}

void Ball :: setThickness() {
  thickness = 2;
}

void Ball :: increaseRadius() {
  auto vel = getVelocity();
  int id = getID();
  setVelocity(vel.x * (1 + id * 1.0 / 10000.f), vel.y);
  return;
  // float radius = getRadius();
  // radius += 0.5;
  // setRadius(radius);  
  // auto velocity = getVelocity();
  // // velocity += sf :: Vector2f(5, 5);
  // setVelocity(velocity.x * 1.5, velocity.y);
}

void Ball :: reverse() {
  motion(-1);
}
