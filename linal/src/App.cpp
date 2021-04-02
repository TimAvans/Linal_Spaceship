#include "../include/App.hpp"
#include <SFML/Graphics.hpp>
#include "../include/Vector.hpp"
#include <iostream>
#include "../include/Transform.hpp"

const int screenWidth = 800;
const int screenHeight = 600;

App::App()
	: window_(sf::RenderWindow{ sf::VideoMode{screenWidth, screenHeight}, "Spaceship", sf::Style::Close }) {
	window_.setKeyRepeatEnabled(false);
	auto view = window_.getDefaultView();
	auto& size = view.getSize();
	view.setSize(size.x, -size.y);
	window_.setView(view);

	std::vector<Vector3> points = {
	{ 310, 310, 10 },
	{ 310, 410, 10 },
	{ 410, 410, 10 },
	{ 410, 310, 10 },

	{ 310, 310, 110 },
	{ 310, 410, 110 },
	{ 410, 410, 110 },
	{ 410, 310, 110 },
	};

	std::vector<std::pair<int, int>> lines = {
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0},
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},
		{4, 5},
		{5, 6},
		{6, 7},
		{7, 4}
	};

	obj = { points, lines };

}

void App::run() {
	while (window_.isOpen())
	{
		sf::Event event;
		bool down = false;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left)
				{
					down = true;
				}
			}			
			else if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Left)
				{
					down = false;
				}				
				
				if (event.key.code == sf::Keyboard::Up)
				{
					obj.move();
				}
			}

			if (down)
			{
				obj.rotate_object();
			}
		}
		window_.clear();
		render.draw({ obj }, &window_);
		window_.display();
	}
}

int main() {
	App app;
	app.run();
	app.run();
}