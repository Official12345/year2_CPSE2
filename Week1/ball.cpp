#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>

ball::ball(sf::Vector2f ballspeed, sf::Vector2f position, float size) :
	ballspeed{ballspeed},
	position{ position },
	size{ size }
{	
circle.setRadius(size);
circle.setPosition(position); 
LR_box.setPosition(position.x, position.y + size / 2);
LR_box.setSize({ size * 2, size});
TB_box.setPosition(position.x + size / 2, position.y);
TB_box.setSize({ size, size * 2});
}

void ball::draw(sf::RenderWindow & window) const{
	//window.draw(circle);
	window.draw(LR_box);
	window.draw(TB_box);
}

void ball::move() {
	position += ballspeed;
	circle.move(ballspeed);
	LR_box.move(ballspeed);
	TB_box.move(ballspeed);
}

void ball::negmove() {
	position -= ballspeed;
	circle.move(-ballspeed);
	LR_box.move(-ballspeed);
	TB_box.move(-ballspeed);
}

/*void ball::move() {
	position += ballspeed;
	circle.setPosition(position);
	LR_box.setPosition(position);
	TB_box.setPosition(position);
}
*/

void ball::jump(sf::Vector2f target) {
	position = target;
}

void ball::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}

float ball::getX() {
	return position.x;
}

float ball::getY() {
	return position.y;
}

sf::Vector2f ball::getSpeed() {
	return ballspeed;
}

void ball::setSpeedX(float speed) {
	ballspeed.x = speed;
}

void ball::setSpeedY(float speed) {
	ballspeed.y = speed;
}

float ball::getBallSize() {
	return size;
}

void ball::setRadius(float r) {
	circle.setRadius(r);
}

void ball::setPosition(sf::Vector2f position) {
	circle.setPosition(position);
}

sf::Vector2f ball::getPosition() {
	return position;
}
sf::FloatRect ball::getGlobalBounds() {
	return circle.getGlobalBounds();
}


/*void ball::detect(screenObject & object) {
	//topwall
	if ( getY() == object.getPosition().y + object.getPosition().y) {
		setSpeedY(getSpeed().y * -1);
		std::cout << "topwall" << "\n";
	}
	//bottomwall
	else if (getY() + getBallSize()*2 == object.getPosition().y) {
		setSpeedY(getSpeed().y * -1);
		std::cout << "bottomwall" << "\n";
	}
	//leftwall
	else if (getX() == object.getPosition().x + object.getPosition().x) {
		setSpeedX(getSpeed().x * -1);
		std::cout << "leftwall" << "\n";
	}
	//rightwall
	else if (getX() + getBallSize()*2 == object.getPosition().x) {
		setSpeedX(getSpeed().x * -1);
		std::cout << "rightwall" << "\n";
	}
}
*/


void ball::detect(screenObject & object) {
	if (this != &object) {
		if (getGlobalBounds().intersects(object.getGlobalBounds())) {
			//topwall, bottomwall
			if (TB_box.getGlobalBounds().intersects(object.getGlobalBounds())) {
				negmove();
				setSpeedY(getSpeed().y *-1);
			}
			else if (LR_box.getGlobalBounds().intersects(object.getGlobalBounds())) {
				negmove();
				setSpeedX(getSpeed().x *-1);
			}
		}
	}
}