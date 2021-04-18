#include "../include/Bullet.hpp"

bool Bullet::CheckCollision(DrawableObject& target) {

	Vector3 max{ -INFINITY, -INFINITY, -INFINITY };
	Vector3 min{ INFINITY, INFINITY, INFINITY };
	

	for (int i = 0; i < target.points.size(); ++i) {
		for (int v = 0; v < 3; ++v) {
			if (target.points[i].values[v] < min.values[v]) {
				min.values[v] = target.points[i].values[v];
			}
			if (target.points[i].values[v] > max.values[v]) {
				max.values[v] = target.points[i].values[v];
			}
		}
	}

	for (int i = 0; i < points.size(); ++i) {
		int trues = 0;
		for (int v = 0; v < 3; ++v) {
			if (min.values[v] <= points[i].values[v] && points[i].values[v] <= max.values[v]) {
				trues++;
			}
			else break;
			if (trues == 3) {
				std::cout << "collided" << std::endl;
				shouldDraw = false;
				shouldRemove = true;
				return true;
			}
		}
	}

	return false;
}