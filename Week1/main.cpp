#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "drawable.hpp"
#include "player.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
		std::function< bool() > condition,
		std::function< void() > work
	) : condition(condition),
		work(work)
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[key]()->bool { return sf::Keyboard::isKeyPressed(key); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[button]()->bool { return sf::Mouse::isButtonPressed(button); }
		),
		work(work)
	{}

	void operator()() {
		if (condition()) {
			work();
		}
	}
};

unsigned int screenheight = 480;
unsigned int screenwidth = 640;
int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ screenwidth, screenheight }, "SFML window" };
	ball my_ball{ sf::Vector2f{10,10}, sf::Vector2f{ 320.0, 240.0 }, 30 };
	wall topwall{ sf::Vector2f{ 20.0, 0.0f }, sf::Vector2f{ screenwidth - 40.0f, 20.0f }, sf::Color::Red };
	wall bottomwall{ sf::Vector2f{ 20.0, screenheight - 20.0f }, sf::Vector2f{ screenwidth - 40.0f, 20.0 }, sf::Color::Blue };
	wall leftwall{ sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ 20.0f, (float)screenheight }, sf::Color::Green };
	wall rightwall{ sf::Vector2f{ screenwidth - 20.0f, 0.0 }, sf::Vector2f{ 20.0f, 640.0f }, sf::Color::Yellow };
	player player1{ sf::Vector2f{float(screenwidth/2), float((screenheight/2)+50)}, sf::Vector2f{500, 30}, sf::Color::Red };
	

	action actions[] = {
		action(sf::Keyboard::Left,  [&]() { player1.inputMove(sf::Vector2f(-1.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { player1.inputMove(sf::Vector2f(+1.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { player1.inputMove(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down,  [&]() { player1.inputMove(sf::Vector2f(0.0, +1.0)); }),
		//action(sf::Mouse::Left,     [&]() { player1.jump(sf::Mouse::getPosition(window)); })
	};
	

	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}

		window.clear();
		my_ball.draw(window);
		topwall.draw(window);
		bottomwall.draw(window);
		leftwall.draw(window);
		rightwall.draw(window);
		player1.draw(window);
		window.display();

		my_ball.detect(topwall);
		my_ball.detect(bottomwall);
		my_ball.detect(rightwall);
		my_ball.detect(leftwall);
		my_ball.detect(player1);
		my_ball.move();

		//std::cout << "ball x: " << my_ball.getPosition().x << "\n";
		//std::cout << "wall x: " << topwall.getPosition().x + topwall.getSize().x << "\n";
		sf::sleep(sf::milliseconds(10));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}

