#include <SFML/Graphics.hpp>

#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

class screenObject {
public:
	virtual void draw() {};
	virtual void detect() {};
	virtual sf::Vector2f getPosition() =0;
	virtual void setPosition(sf::Vector2f) {};
	virtual sf::Vector2f getSize() { return { 0,0 }; };
	virtual sf::FloatRect getGlobalBounds() = 0;
};

#endif