#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "../SimpleGameSFML/Resources/Fonts/Fonts.hpp"
#include "../SimpleGameSFML/Utilities/hkpLogger.hpp"
#include <string>

namespace hkp {
    class Buttons {
    public:
        Buttons(std::string name, sf::Font font, sf::Vector2u size);
        ~Buttons() = default;

        void setPosition(sf::Vector2f pos);
        void setText(const std::string& label);
        void draw(sf::RenderWindow& window) ;

    private:
        Logger logger;
        sf::Font font;
        unsigned width;
        unsigned height;
        sf::Vector2f position;
        sf::Text text;
        std::string name;
    };
}


