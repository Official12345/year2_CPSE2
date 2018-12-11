#include "ball.hpp"
#include "wall.hpp"

class collision {
private:
	wall & rect;
	ball & circle;

public:
	collision(wall & rect, ball & circle);
	void detect();

};