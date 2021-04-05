#include "../include/App.hpp"
#include <SFML/Graphics.hpp>
#include "../include/Vector.hpp"
#include <iostream>
#include "../include/Transform.hpp"

const int screenWidth = 1920;
const int screenHeight = 1080;

App::App()
	: window_(sf::RenderWindow{ sf::VideoMode{screenWidth, screenHeight}, "Spaceship", sf::Style::Close }) {
	window_.setKeyRepeatEnabled(false);
	auto view = window_.getDefaultView();
	auto& size = view.getSize();
	view.setSize(size.x, -size.y);
	window_.setView(view);

	std::vector<Vector3> points = {
	{ 0, 0, 20 },
	{ 0, 50, 20 },
	{ 50, 50, 20 },
	{ 50, 0, 20 },

	{ 0, 0, 30 },
	{ 0, 50, 30 },
	{ 50, 50, 30 },
	{ 50, 0, 30 },

	{25, 75, 25},

	//{310, 335, 60},
	//{300, 335, 60},
	//{280, 260, 60},
	//{310, 260, 60},

	//{410, 335, 60},
	//{420, 335, 60},
	//{440, 260, 60},
	//{410, 260, 60},
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
		{7, 4},
		{6, 8},
		{5, 8},
		{1, 8},
		{2, 8},

		//{9, 10},
		//{10, 11},
		//{11, 12},
		//{12, 9},

		//{13, 14},
		//{14, 15},
		//{15, 16},
		//{16, 13},
	};

	Vector3 heading{ 0, 1, 0};

	objects.push_back({points, lines, heading});
}

void App::run() {
	DrawableObject obj = objects[0];

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

				if (event.key.code == sf::Keyboard::W)
				{
					obj.rotate_object({ -1, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::S)
				{
					obj.rotate_object({ 1, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::A)
				{
					obj.rotate_object({ 0, -1, 0 });

				}
				if (event.key.code == sf::Keyboard::D)
				{
					obj.rotate_object({ 0, 1, 0 });

				}
				if (event.key.code == sf::Keyboard::Q)
				{
					obj.rotate_object({ 0, 0, -1 });
				}
				if (event.key.code == sf::Keyboard::E)
				{
					obj.rotate_object({ 0, 0, 1 });
				}
				if (event.key.code == sf::Keyboard::LShift) {
					obj.move(true);
				}
				if (event.key.code == sf::Keyboard::LControl) {
					obj.move(false);
				}				
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
}