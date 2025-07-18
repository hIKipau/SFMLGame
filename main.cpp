#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode({1000, 600}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setPosition({100,100});
    shape.setFillColor(sf::Color(200,30,10));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                    shape.move({0,-1});

                }else if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
					shape.move({ 0,1 });

				}else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
					shape.move({ 1,0 });
				}

            }
			
        }

        window.clear(sf::Color(20,5,5));
        window.draw(shape);
        window.display();
    }

    return 0;
}