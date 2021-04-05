#pragma once 
#include <SFML/Graphics/RenderWindow.hpp>
#include "Renderer.hpp"

class App {
public: 
	App();

	void run();

private:
	sf::RenderWindow window_;
	Renderer render{};
	std::vector<DrawableObject> objects{};
};