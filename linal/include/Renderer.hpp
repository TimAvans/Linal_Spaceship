#pragma once
#include <vector>
#include "../include/DrawableObject.hpp"
#include <SFML/Graphics.hpp>

class Renderer {
public:
	void draw(std::vector<DrawableObject> objects, sf::RenderWindow* window);
	sf::RenderWindow* get_window();
private:
	sf::RenderWindow* window_;
};