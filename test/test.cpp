#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
// #include 

int main() {
    // Create a window just to keep the program running
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Sound Test");
    
    // Load sound file
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/home/layman/layman/Projects/SFML/audio/golf_ball.wav")) {
        // Error handling if the file fails to load
        return EXIT_FAILURE;
    }
    
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Play the sound
    sound.play();

    // Keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return EXIT_SUCCESS;
}
