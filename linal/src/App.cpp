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
}

void App::run() {
	while (window_.isOpen())
	{
		sf::Event event;

		bool down = false;

		po.pulse();

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
					ship.rotate_object({ -0.5, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::S)
				{
					ship.rotate_object({ 0.5, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::A)
				{
					ship.rotate_object({ 0, -0.5, 0 });
				}
				if (event.key.code == sf::Keyboard::D)
				{
					ship.rotate_object({ 0, 0.5, 0 });
				}
				if (event.key.code == sf::Keyboard::Q)
				{
					ship.rotate_object({ 0, 0, -0.5 });
				}
				if (event.key.code == sf::Keyboard::E)
				{
					ship.rotate_object({ 0, 0, 0.5 });
				}
				if (event.key.code == sf::Keyboard::LShift) {
					ship.move(true);
				}
				if (event.key.code == sf::Keyboard::LControl) {
					ship.move(false);
				}				
				if (event.key.code == sf::Keyboard::Right) {
					po.rotate_object({0.5, 0.5 ,0});
				}					
				if (event.key.code == sf::Keyboard::Space) {
					objects.push_back(ship.shoot_bullet());
				}								
			}
		}
		window_.clear();

		for (size_t i = 0; i < objects.size(); ++i)
		{
			objects[i].move(true);
		}

		std::vector<DrawableObject> drawables;
		drawables.push_back(ship);
		drawables.push_back(po);
		for (size_t i = 0; i < objects.size(); ++i)
		{
			drawables.push_back(objects[i]);
		}

		render.draw(drawables, &window_);
		window_.display();
	}
}

int main() {
	App app;
	app.run();
}