#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include "ball.h"
#include "circle.h"
#include "util.h"
#include "time.h"


const int screen_w = 800;
const int screen_h = 600;
const int circle_R = 300;
const int ball_R   = 7;

sf::Color generateRainbowColor(float position) {
    int i = position * 6;
    float f = position * 6 - i;
    float q = 1 - f;
    switch(i % 6){
        case 0: return sf::Color(255, 255 * f, 0); break;
        case 1: return sf::Color(255 * q, 255, 0); break;
        case 2: return sf::Color(0, 255, 255 * f); break;
        case 3: return sf::Color(0, 255 * q, 255); break;
        case 4: return sf::Color(255 * f, 0, 255); break;
        case 5: return sf::Color(255, 0, 255 * q); break;
    }
    return sf::Color();
}

sf::Color generateRandomColor() {
    // Seed the random number generator with the current time
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random values for red, green, and blue components
    sf::Uint8 r = std::rand() % 255;
    sf::Uint8 g = std::rand() % 255;
    sf::Uint8 b = std::rand() % 255;

    // Return the generated color
    return sf::Color(r, g, b);
}

sf::Vector2f generateRandomPosition() {
    // Seed the random number generator with the current time
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random x and y coordinates
    int xCenter = screen_w / 2;
    int yCenter = screen_h / 2;
    int xLimit  = xCenter - circle_R / 2; 
    int yLimit  = yCenter - circle_R / 2; 

    float x = static_cast<float>(std::rand() % circle_R + xLimit);
    float y = static_cast<float>(std::rand() % circle_R + yLimit);
    return sf::Vector2f(x, y);
}

int main()
{
    // create the window

    int xCenter = screen_w / 2;
    int yCenter = screen_h / 2;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(screen_w, screen_h), "My window");

    // run the program as long as the window is open
    std :: vector<Ball> allBalls(100);
    Circle circle;
    circle.setRadius(circle_R);
    circle.setPosition(xCenter, yCenter);
    // circle.print();
    int i = 0;
    for (auto &newBall : allBalls) {
      i++;
      newBall.setFillColor(generateRandomColor());
      newBall.setRadius(ball_R);
      newBall.setPosition(generateRandomPosition().x, generateRandomPosition().y);
      // newBall.print();
    }
    // exit(0);
    bool start = false;
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            
        }

        // clear the window with black color
        
        window.clear(sf::Color::Black);

        if (sf :: Keyboard::isKeyPressed(sf ::Keyboard :: Space)) {
          start = true;
        }

        if (!start) {
          continue;
        }

        circle.draw(window);

        for (auto &B : allBalls) {
          B.draw(window);
          B.motion();    
          if (IsCollision(B, circle)) {
              while(IsCollision(B, circle)) {
                B.motion(-1);
              }              
             handleCollision(B, circle);
          }                          
        }
        
        window.display();
    }

    return 0;
}
