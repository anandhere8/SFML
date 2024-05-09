#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a Music object
    sf::Music music;

    // Open the audio file

    std :: string audioFilePath = "/home/layman/Downloads/wavin-flag.wav";
    if (!music.openFromFile(audioFilePath)) {
        std::cerr << "Failed to open audio file!" << std::endl;
        return 1;
    }
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Keyboard Input");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    music.play();
                } else if (event.key.code == sf :: Keyboard :: Key :: A) {
                    music.pause();
                } else if (event.key.code == sf :: Keyboard :: Key :: X) {
                    music.stop();
                }                
            }
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}
