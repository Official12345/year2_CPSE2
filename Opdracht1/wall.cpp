#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color):
	position{position},
	size{size}
{
	rect.setPosition(position);
	rect.setSize(size);
	rect.setFillColor(color);
}


void wall::draw(sf::RenderWindow & window) const {
	window.draw(rect);
}

sf::FloatRect wall::getGlobalBounds() {
	return rect.getGlobalBounds();
}

sf::Vector2f wall::getPosition() {
	return position;
}

sf::Vector2f wall::getSize() {
	return size;
}

