#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class player : public screenObject {
public:

	player(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) const;
	sf::Vector2f getPosition();
	sf::Vector2f player::getSize() override;
	sf::FloatRect getGlobalBounds() override;
	void inputMove(sf::Vector2f delta);

private:
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Vector2f size;
};

#endif
