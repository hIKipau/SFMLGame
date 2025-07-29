#include "Buttons.hpp"

hkp::Buttons::Buttons(std::string name,sf::Font font, sf::Vector2u size)
    : logger(Logger::Mode::DEBUG),
      width(size.x),
      height(size.y),
      position(100, 100),
      text(font),
      name(name)
{
    // Логируем создание кнопки
    logger.log(Logger::INFO, "Создание кнопки размером " +
               std::to_string(width) + "x" + std::to_string(height));
    logger.log(Logger::INFO, "Кнопка: " + name + " создана");

    // Настраиваем текст
    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
}

void hkp::Buttons::setPosition(sf::Vector2f pos) {
    position = pos;
    text.setPosition({ (pos.x),(pos.y)});
}

void hkp::Buttons::setText(const std::string& label) {
    text.setString(label);
}

void hkp::Buttons::draw(sf::RenderWindow& window) {
    window.draw(text);
}