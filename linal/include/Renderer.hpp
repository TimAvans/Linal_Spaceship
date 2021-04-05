#pragma once
#include <vector>
#include "../include/DrawableObject.hpp"
#include <SFML/Graphics.hpp>
#include "../include/Transform.hpp"
#include "Camera.hpp"

class Renderer {
public:
	void draw(std::vector<DrawableObject> objects, sf::RenderWindow* window);
	sf::RenderWindow* get_window();
	Camera c_{};
private:
	sf::RenderWindow* window_;


};