#include "../include/Ship.hpp"

Bullet Ship::shoot_bullet(PulsatingObject* po) {
	return Bullet{ points[8], this->heading, po };
};

