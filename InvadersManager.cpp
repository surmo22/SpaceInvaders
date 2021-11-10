#include "InvadersManager.h"
InvadersManager::InvadersManager() {
	texture.loadFromFile("invader.png");
	direction = 1;
	speed = 0.03f;
	spawn();
}
void InvadersManager::draw(RenderWindow& window) {
	for (auto& i : invaders) {
		i.draw(window);
	}
}

void InvadersManager::move(Window& window) {
	double min = window.getSize().x;
	double max = 0;
	double ymin = window.getSize().y;

	for (auto& i : invaders) {
		if (i.getPos().x > max) max = i.getPos().x;
		if (i.getPos().x < min) min = i.getPos().x;
		if (i.getPos().y < ymin) ymin = i.getPos().y;
	}

	if (max >= (double)WindowW - 40.0 - speed) {
		direction = -1;
		for (auto& i : invaders) {
			i.move(-speed, window,40);
		}
	}
	else if (min <= speed) {
		direction = 1;
		for (auto& i : invaders) {
			i.move(speed,window, 40);
		}
	}
	else {
		for (auto& i : invaders) {
			i.move(speed * direction,window);
		}
	}

}
bool InvadersManager::checkForLoose() {
	double ymax = 0;
	for (auto& i : invaders) {
		if (i.getPos().y > ymax) ymax = i.getPos().y;
	}
	if (ymax >= (double)WindowH-60.0) {
		return 1;
	}
	return 0;
}
void InvadersManager::fire(Bullet& a) {
	int index = rand() % invaders.size();
	invaders[index].shoot(a);
}
bool InvadersManager::checkForHit(Bullet& a,Window& window) {
	for (unsigned int i = 0; i < invaders.size(); i++) {
		if (a.getGlobalBounds().intersects(invaders[i].getGlobalBounds())) {
			invaders.erase(begin(invaders) + i);
			if (!invaders.size()) {
				killCounter = 0;
				spawn();
				wave++;
				speed = (float)window.getSize().x / 20000 + (wave * 0.03f);
			}
			killCounter++;
			speed += 0.001f;
			return 1;
		}
	}
	return 0;
}
void InvadersManager::spawn() {
	for (float i = 60; i < 210; i += 50) {
		for (float j = 10; j <= 260; j += 50) {
			Invader a(j, i, texture);
			invaders.push_back(a);
		}
	}
}