#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

using namespace sf;
class Ship {
public:
	virtual void move(float x, Window& window, float y = 0) = 0;
	virtual void shoot(Bullet& a) = 0;
	virtual void draw(RenderWindow& window) = 0;
};