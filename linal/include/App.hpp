#pragma once 
#include <SFML/Graphics/RenderWindow.hpp>

class App {
public: 
	App();

	void run();

private:
	sf::RenderWindow window_;
};