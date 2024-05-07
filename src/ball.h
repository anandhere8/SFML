// ball.h
#ifndef BALL_H
#define BALL_H

#include "circle.h" // Include the Circle class header

// Ball class declaration inheriting from Circle
class Ball : public Circle {
  public: 
    void motion(int reverse = 1);
};

#endif

