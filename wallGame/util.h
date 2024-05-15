#include "ball.h"
#include "boundary.h"

float sq(float a);
bool IsCollision(Ball &ball, Boundary &wall, sf :: Vector2f center);
void handleCollision(Ball &ball, Boundary &wall);
void playSound();
bool isBallOutsideCircle(Ball &B, Circle &C);

