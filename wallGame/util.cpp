#include "ball.h"
#include "circle.h"
#include "boundary.h"
#include <math.h>
#include <SFML/Audio.hpp>
#include "util.h"

float sq(float a) {
  return a * a;
}



bool IsCollision(Ball &ball, Boundary &wall, sf :: Vector2f center) {
  float dis = wall.getRadius() - abs(ball.getCenter().x - center.x);
  return dis < 20 + ball.getRadius();
}

void handleCollision(Ball &ball, Boundary &wall) {
  auto vel = ball.getVelocity();
  ball.setVelocity(vel.x * -1, 0);
}


void playSound() {
  sf :: SoundBuffer buffer;

  if (!buffer.loadFromFile("/home/layman/layman/Projects/SFML/audio/golf_ball.wav")) {
    printf("Failed to load the audio file.\n");
    // return EXIT_FAILURE;
  }
  sf :: Sound sound;
  sound.setBuffer(buffer);
  sound.play();
}

bool isBallOutsideCircle(Ball &B, Circle &C) {
  float dis = sq(B.getCenter().x - C.getCenter().x) + sq(B.getCenter().y - C.getCenter().y);
  float rad = sq(C.getRadius());
  if (rad > dis) {
    
    return false;
  }
  printf("Outside\n");
  return true;
}
