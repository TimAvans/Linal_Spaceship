#pragma once 
#include <SFML/Graphics/RenderWindow.hpp>
#include "Renderer.hpp"
#include "Ship.hpp"
#include "../include/PulsatingObject.hpp"

class App {
public: 
	App();

	void run();

private:

	std::vector<Vector4> points = {
	{ 10, 10, 12, 1 },
	{ 10, 15, 12, 1 },
	{ 15, 15, 12, 1 },
	{ 15, 10, 12, 1 },

	{ 10, 10, 13, 1 },
	{ 10, 15, 13, 1 },
	{ 15, 15, 13, 1 },
	{ 15, 10, 13, 1 },

	{12.5, 17.5, 12.5, 1},
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

	std::vector<Vector4> points2 = {
		{ 10, 60, 10, 1 },
		{ 10, 65, 10, 1 },
		{ 15, 65, 10, 1 },
		{ 15, 60, 10, 1 },

		{ 10, 60, 15, 1 },
		{ 10, 65, 15, 1 },
		{ 15, 65, 15, 1 },
		{ 15, 60, 15, 1 },
	};

	std::vector<std::pair<int, int>> lines2 = {
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
	};

	Vector3 heading2{ 0, 0, 0 };


	sf::RenderWindow window_;

	Renderer render{};

	std::vector<Bullet> objects;

	Ship ship{points, lines, heading};

	PulsatingObject po{ points2, lines2, heading2 };


};