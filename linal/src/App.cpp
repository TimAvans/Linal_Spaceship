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

	ship = new Ship( points, lines, heading );
	po = new PulsatingObject( points2, lines2, heading2 );

	drawables.push_back(ship);
	drawables.push_back(po);
	drawables.back()->rotate_object({ 0.5, 0.5 ,0 });
}

bool shouldRemove(Bullet b) {
	return b.shouldRemove;
}

void App::run() {
	sf::Clock deltaClock;
	float dt;

	while (window_.isOpen())
	{
		sf::Event event;

		bool down = false;

		//Delete kogel
 		for (size_t i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->shouldRemove) {
				//objects[i]->target = nullptr;
				auto del = objects[i];
				objects[i] = objects.back();
				objects.pop_back();
				delete del;
			}
		}


		if (auto x = dynamic_cast<PulsatingObject*>(drawables.back())) {
			x->pulse();
		}

		if (drawables.back()->shouldRemove) {
			auto del = drawables.back();
			drawables.pop_back();
			delete del;
		}

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
					ship->rotate_object({ -0.5, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::S)
				{
					ship->rotate_object({ 0.5, 0, 0 });
				}
				if (event.key.code == sf::Keyboard::A)
				{
					ship->rotate_object({ 0, -0.5, 0 });
				}
				if (event.key.code == sf::Keyboard::D)
				{
					ship->rotate_object({ 0, 0.5, 0 });
				}
				if (event.key.code == sf::Keyboard::Q)
				{
					ship->rotate_object({ 0, 0, -0.1 });
				}
				if (event.key.code == sf::Keyboard::E)
				{
					ship->rotate_object({ 0, 0, 0.25 });
				}
				if (event.key.code == sf::Keyboard::LShift) {
					ship->move(true);
				}
				if (event.key.code == sf::Keyboard::LControl) {
					ship->move(false);
				}								
				if (event.key.code == sf::Keyboard::Space) {
 					objects.push_back(ship->shoot_bullet());
				}								
			}
		}

		for (size_t i = 0; i < objects.size(); ++i)
		{
			objects[i]->move(true);
			if (objects[i]->CheckCollision(*drawables.back())) {
				drawables.back()->shouldRemove = true;
			}
			
		}

		std::vector<DrawableObject> drawables2;

		for (size_t i = 0; i < drawables.size(); ++i)
		{
			drawables2.push_back(*drawables[i]);
		}

		for (size_t i = 0; i < objects.size(); ++i)
		{
			drawables2.push_back(*objects[i]);
		}

		window_.clear();

		render.draw(drawables2, &window_);

		window_.display();

		//std::cout << dt << std::endl;
	}
}

int main() {
	App app;
	app.run();
}