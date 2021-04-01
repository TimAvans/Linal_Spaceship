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
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "broeder wat" << std::endl;
            }
        }
        std::vector<Vector3> points = {
            { 10, 10, 1 },
            { 10, 110, 1 },
            { 110, 110, 1 },
            { 110, 10, 1 },

        };        
        
        std::vector<Vector3> points2 = {
            { 200, 200, 1 },
            { 200, 300, 1 },
            { 300, 300, 1 },
            { 300, 200, 1 }
        };        
        
        std::vector<std::pair<int, int>> lines = {
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 0},
        };



        DrawableObject obj{points, lines};
        DrawableObject obj2{points2, lines};
        render.draw({obj, obj2}, &window_);

        window_.display();
    }
}

int main() {
	App app;
	app.run();
	app.run();
}