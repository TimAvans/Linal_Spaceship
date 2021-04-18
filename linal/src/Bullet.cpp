#include "../include/Bullet.hpp"

bool Bullet::CheckCollision(DrawableObject& target) {

	auto bounding_box = target.getBoundingBox();

	for (int i = 0; i < points.size(); ++i) {
		int trues = 0;
		for (int v = 0; v < 3; ++v) {
			if (bounding_box.second.values[v] <= points[i].values[v] && points[i].values[v] <= bounding_box.first.values[v]) {
				trues++;
			}
			else break;
			if (trues == 3) {
				shouldDraw = false;
				shouldRemove = true;
				return true;
			}
		}
	}

	return false;
}