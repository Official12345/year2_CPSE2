#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall : public screenObject{
public:

	wall(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) const;
	sf::Vector2f getPosition();
	sf::Vector2f getSize() override;
	sf::FloatRect getGlobalBounds() override;

private:
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Vector2f size;
};

#endif
