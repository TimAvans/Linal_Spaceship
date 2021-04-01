#include "../include/Renderer.hpp"

sf::RenderWindow* Renderer::get_window() {
	return window_;
}

void Renderer::draw(std::vector<DrawableObject> objects, sf::RenderWindow* window) {
    for each (auto object in objects)
    {
        for each (auto line in object.lines)
        {
            sf::Vertex drawable_line[] = {
                sf::Vertex(sf::Vector2f(object.points[line.first].x(), object.points[line.first].y())),
                sf::Vertex(sf::Vector2f(object.points[line.second].x(), object.points[line.second].y())),
            };

            window->draw(drawable_line, 8, sf::Lines);
        }
    }
}