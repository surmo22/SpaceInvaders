#pragma once
#include "Invader.h"
#include "Bullet.h"
using namespace sf;
class InvadersManager {
	std::vector<Invader> invaders;
	Texture texture;
	int direction;
	float speed;
	void spawn();
	int wave = 0;
	int killCounter = 0;
public:
	InvadersManager();
	void draw(RenderWindow& window);
	void move(Window& window);
	bool checkForLoose();
	void fire(Bullet& a);
	bool checkForHit(Bullet& a, Window& window);
};