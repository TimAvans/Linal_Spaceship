#include "../include/Ship.hpp"

Bullet* Ship::shoot_bullet() {
	return new Bullet{ points[8], this->heading};
};