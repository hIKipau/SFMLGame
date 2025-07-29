#include <SFML/Graphics.hpp>
#include "../SimpleGameSFML/Resources/Fonts/Fonts.hpp"
#include "../SimpleGameSFML/Utilities/hkpLogger.hpp"
#include "Buttons.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 800}), "SFML works!", sf::Style::Default);
    window.setFramerateLimit(200);
    sf::CircleShape shape(100.f);
    shape.setPosition({100,100});
    shape.setFillColor(sf::Color(200,30,10));
    sf::Cursor cursor( sf::Cursor::Type::Text);
    sf::Font font(hkp::Freesensaton_f);
    sf::Text text1(font);
    text1.setPosition({400,300});
    hkp::Buttons Button("penis",font, {400,300});

    int count = 0;
    sf::Clock clock;
    hkp::Logger logger(hkp::Logger::DEBUG);


    clock.start();
    logger.log(hkp::Logger::INFO,"CLOCK STARTED");

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                logger.log(hkp::Logger::INFO,"KEY PRESSED");

                if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                    logger.log(hkp::Logger::INFO,"KEY IS: W");
                    shape.move({0,-1});
                }
            }
        }



        ++count;
        Button.draw(window);
        window.clear(sf::Color(20,5,5));
        window.draw(shape);
        if (clock.getElapsedTime() >= sf::seconds(1)) {
                text1.setString( std::to_string(count));
                count = 0;
                clock.restart();
        }
        window.draw(text1);
        window.display();
    }

    return 0;
}