#include "collision.hpp"

collision::collision(wall & rect, ball & circle) :
	rect(rect),
	circle(circle)
{}

void collision::detect() {
	//bottomwall
	if (circle.getY() + circle.getSize() * 2 >= 460) {
		circle.setSpeedY(circle.getSpeed().y *= -1.0);
	}
	else if (circle.getY() + circle.getSize() * 2 >= 620) {
		circle.setSpeedX(circle.getSpeed().x *= -1.0);
	}
	else if (circle.getY() + circle.getSize() * 2 >= 20) {
		circle.setSpeedY(circle.getSpeed().x *= -1.0);
	}
	else if (circle.getY() + circle.getSize() * 2 >= 20) {
		circle.setSpeedX(circle.getSpeed().y *= -1.0);
	}


	/*//rightwall
	else if (position.x + size * 2 >= 620) {
		ballspeed.x *= -1;
	}
	//leftwall
	else if (position.x <= 20) {
		ballspeed.x *= -1;
	}
	//topwall
	else if (position.y <= 20) {
		ballspeed.y *= -1;
	}*/
}