#include "../include/Renderer.hpp"

sf::RenderWindow* Renderer::get_window() {
	return window_;
}

void Renderer::draw(std::vector<DrawableObject> objects, sf::RenderWindow* window) {
    for each (auto object in objects)
    {     

        for (size_t i = 0; i < object.points.size(); ++i)
        {
            Matrix persp = c_.projection_matrix;
           /* Matrix translationm = Transform::translation_matrix(c_.points[0]);
            Matrix camm = c_.translation_matrix();
            
            auto r1 = Transform::multiply(persp, camm);
            auto r2 = Transform::multiply(r1, translationm);

            auto vec = Transform::multiply(object.points[i], r2);

            std::cout << " x: " << object.points[i].values[0] << " y: " << object.points[i].values[1] << " z: " << object.points[i].values[2] << " w: " << object.points[i].values[3] << std::endl;

            object.points[i].values[0] = (800 / 2) + ((vec.values[0] / vec.values[3]) * 800 / 2);
            object.points[i].values[1] = (600 / 2) + ((vec.values[1] / vec.values[3]) * 600 / 2);
        
            std::cout << " x: " << object.points[i].values[0] << " y: " << object.points[i].values[1] << " z: " << object.points[i].values[2] << " w: " << object.points[i].values[3] << std::endl;*/
        
            object.points[i] = Transform::multiply(object.points[i], persp);
        
        }

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