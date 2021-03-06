#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
	size{ size }
{
	rect.setPosition(position);
	rect.setSize(size);
	rect.setFillColor(color);
}


void player::draw(sf::RenderWindow & window) const {
	window.draw(rect);
}

sf::FloatRect player::getGlobalBounds() {
	return rect.getGlobalBounds();
}

sf::Vector2f player::getPosition() {
	return position;
}

sf::Vector2f player::getSize() {
	return size;
}

void player::inputMove(sf::Vector2f delta) {
	position += delta;
	rect.setPosition(position);
}

void player::jump(sf::Vector2f target) {
	position = target;
	rect.setPosition(target);
}

void player::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}