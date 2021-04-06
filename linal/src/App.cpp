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

				if (event.key.code == sf::Keyboard::W)
				{
					ship.rotate_object({ -1, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::S)
				{
					ship.rotate_object({ 1, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::A)
				{
					ship.rotate_object({ 0, -1, 0 });
				}
				if (event.key.code == sf::Keyboard::D)
				{
					ship.rotate_object({ 0, 1, 0 });
				}
				if (event.key.code == sf::Keyboard::Q)
				{
					ship.rotate_object({ 0, 0, -1 });
				}
				if (event.key.code == sf::Keyboard::E)
				{
					ship.rotate_object({ 0, 0, 1 });
				}
				if (event.key.code == sf::Keyboard::LShift) {
					ship.move(true);
				}
				if (event.key.code == sf::Keyboard::LControl) {
					ship.move(false);
				}				
				if (event.key.code == sf::Keyboard::Right) {
					render.c_.move(true);
				}					
				if (event.key.code == sf::Keyboard::Space) {
					objects.push_back(ship.shoot_bullet());
				}						
				if (event.key.code == sf::Keyboard::BackSpace) {
					objects.pop_back();
				}				
			}
		}
		window_.clear();

		for (size_t i = 0; i < objects.size(); ++i)
		{
			objects[i].move(true);
		}




		std::vector<DrawableObject> oogabooga;
		oogabooga.push_back(ship);
		for (size_t i = 0; i < objects.size(); ++i)
		{
			oogabooga.push_back(objects[i]);
		}

		render.draw(oogabooga, &window_);
		window_.display();
	}
}

int main() {
	App app;
	app.run();
}