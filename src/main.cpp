#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "time.h"

#include "ball.h"
#include "circle.h"
#include "util.h"
#include "info.h"


const int screen_w = 600;
const int screen_h = 800;
const int circle_R = 280;
const int ball_R   = 7;
const int NumberOfBalls = 10 ;



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
    float y = static_cast<float>(std::rand() % circle_R / 2 + yLimit);
    return sf::Vector2f(x, y);
}

int getRandomInt(int a, int b) {
  // return 7;
  int diff = b - a;
  return std :: rand() % diff + a;
}



int main()
{

    int xCenter = screen_w / 2;
    int yCenter = screen_h / 2;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(screen_w, screen_h), "Ball Simulation", 
    sf::Style::Default, settings);
    window.setFramerateLimit(600);

    
    
    Info info;

    std :: vector<Ball> allBalls(NumberOfBalls);
    Circle circle;
    circle.setRadius(circle_R);
    circle.setPosition(xCenter, yCenter);

    int i = 0;
    for (auto &newBall : allBalls) {
      // i++;
      newBall.setFillColor(generateRandomColor());
      newBall.setRadius(getRandomInt(ball_R, 3 * ball_R));
      auto center = generateRandomPosition();
      newBall.setPosition(center.x, center.y);
      newBall.setInitialPosition(center.x, center.y);


      // newBall.print();
    }
    // exit(0);
    int loopCounter = 1;
    bool start = false;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/home/layman/layman/Projects/SFML/audio/water.wav")) {
        // Error handling if the file fails to load
        return EXIT_FAILURE;
    }
    
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setBuffer(buffer);
    sound.setPlayingOffset(sf::Time::Zero);
    sound.setLoop(true);
    sound.setPitch(1);
    sound.setVolume(100);

    // Play the sound

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();                     
        }      
        

        if (sf :: Keyboard::isKeyPressed(sf ::Keyboard :: Space)) {
          start = true;
        }

        if (!start) {
          continue;
        }
        // clear the window with black color
        window.clear(sf :: Color::Black);

        for (auto &B : allBalls) {
          B.draw(window); // drawing the ball on the window and lines on the texture
          B.motion();    
          if (IsCollision(B, circle)) {

              
              sound.play();
              while(IsCollision(B, circle)) {
                B.motion(-1);
              }    
             info.increaseCollisionCount();       
             handleCollision(B, circle);
          }                          
        }   
        
        
        
        circle.draw(window);
        
        info.draw(window);

        window.display();
        

                              

    }

    return 0;
}
