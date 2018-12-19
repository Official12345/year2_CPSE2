#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class player : public screenObject {
public:

	player(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) const;
	sf::Vector2f getPosition();
	sf::Vector2f getSize() override;
	sf::FloatRect getGlobalBounds() override;
	void inputMove(sf::Vector2f delta);
	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

private:
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Vector2f size;
};

#endif
