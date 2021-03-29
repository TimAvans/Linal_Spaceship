#include "../include/App.hpp"

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
	while (true) {
		window_.display();
	}
}

int main() {
	App app;
	app.run();
}