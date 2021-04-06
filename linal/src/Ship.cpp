#include "../include/Ship.hpp"

Bullet Ship::shoot_bullet() {
	return Bullet{ points[8], this->heading };
};

