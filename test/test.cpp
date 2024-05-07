
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#ifdef SFML_SYSTEM_IOS
#include <SFML/Main.hpp>
#endif

std::string resourcesDir()
{
#ifdef SFML_SYSTEM_IOS
    return "";
#else
    return "resources/";
#endif
}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    const float gameWidth = 800;
    const float gameHeight = 600;

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(gameWidth), static_cast<unsigned int>(gameHeight), 32), "SFML Tennis",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::RenderTexture RT;
    RT.create(gameWidth, gameHeight);

    sf::CircleShape CS(50);
    CS.setPosition(gameWidth / 2, gameHeight / 2);
    CS.setFillColor(sf::Color::Green);

    sf::Clock clock;
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Window size changed, adjust view appropriately
            if (event.type == sf::Event::Resized)
            {
                sf::View view;
                view.setSize(gameWidth, gameHeight);
                view.setCenter(gameWidth / 2.f, gameHeight  /2.f);
                window.setView(view);
            }
        }

        // Clear the window
        window.clear(sf::Color(0, 0, 0));

        CS.setPosition(int(clock.getElapsedTime().asSeconds() * gameWidth / 2) % (int)gameWidth, gameHeight / 2);
        RT.draw(CS);


        sf::RectangleShape shadow({ gameWidth, gameHeight });
        shadow.setFillColor(sf::Color(0, 0, 0, 10));
        RT.draw(shadow);

        RT.display();

        window.draw(sf::Sprite(RT.getTexture()));

        window.display();
    }

    return EXIT_SUCCESS;
}