#pragma once
#include "Ship.h"
class Invader : Ship {
	sf::Sprite sprite;
public:
	Invader(float& x, float& y, Texture& texture);
	void move(float x, Window& window, float y = 0);
	void shoot(Bullet& a);
	void draw(RenderWindow& window);
	const sf::Vector2f& getPos();
	FloatRect getGlobalBounds();
};