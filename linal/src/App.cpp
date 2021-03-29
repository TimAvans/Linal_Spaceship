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
        Transform tr{};
        Matrix matrix{};
        
        sf::Vertex line[] = {
            // x->y
            sf::Vertex(sf::Vector2f(x.get_x(), x.get_y())),
            sf::Vertex(sf::Vector2f(y.get_x(), y.get_y())),

            // y->a
            sf::Vertex(sf::Vector2f(y.get_x(), y.get_y())),
            sf::Vertex(sf::Vector2f(a.get_x(), a.get_y())),            
            
            // a->b
            sf::Vertex(sf::Vector2f(a.get_x(), a.get_y())),
            sf::Vertex(sf::Vector2f(b.get_x(), b.get_y())),            
            
            // b->a
            sf::Vertex(sf::Vector2f(b.get_x(), b.get_y())),
            sf::Vertex(sf::Vector2f(x.get_x(), x.get_y())),
        };
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
        window_.draw(line, 8, sf::Lines);
        window_.display();
    }
}

int main() {
	App app;
	app.run();
	app.run();
}