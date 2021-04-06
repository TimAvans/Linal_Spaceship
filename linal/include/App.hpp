#pragma once 
#include <SFML/Graphics/RenderWindow.hpp>
#include "Renderer.hpp"
#include "Ship.hpp"

class App {
public: 
	App();

	void run();

private:

	std::vector<Vector4> points = {
	{ 0, 0, 20, 1 },
	{ 0, 50, 20, 1 },
	{ 50, 50, 20, 1 },
	{ 50, 0, 20, 1 },

	{ 0, 0, 30, 1 },
	{ 0, 50, 30, 1 },
	{ 50, 50, 30, 1 },
	{ 50, 0, 30, 1 },

	{25, 75, 25, 1},
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
	};

	Vector3 heading{ 0, 1, 0 };

	sf::RenderWindow window_;

	Renderer render{};

	std::vector<Bullet> objects;

	Ship ship{points, lines, heading};
};