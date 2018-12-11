#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public  screenObject{
public:

	ball(sf::Vector2f ballspeed, sf::Vector2f position, float size);
	void draw(sf::RenderWindow & window) const;
	void move();
	void negmove();
	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);
	float getX();
	float getY();
	float getBallSize();
	sf::Vector2f getSpeed();
	void setSpeedX(float speed);
	void setSpeedY(float speed);
	void detect(screenObject & object);
	void setRadius(float r);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds() override;

private:
	sf::Vector2f position;
	sf::CircleShape circle;
	sf::Vector2f ballspeed;
	sf::RectangleShape LR_box;
	sf::RectangleShape TB_box;
	float size;
};

#endif
