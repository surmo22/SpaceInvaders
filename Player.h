#pragma once
#include "Ship.h"
#include "Bullet.h"
class Player : public Ship {
	Texture texture;
	sf::Sprite sprite;
public:
	Player();
	void move(float x,Window& window,float y = 0);
	void shoot(Bullet& a);
	bool checkForHit(Bullet& a);
	void draw(RenderWindow& window);
};