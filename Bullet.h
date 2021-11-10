#pragma once
#include <SFML/Graphics.hpp>
#define WindowW 600
#define WindowH 600
using namespace sf;
class Bullet {
	int direction;
	Sprite sprite;
	float speed = 0.10f;
public:
	Bullet(Texture& texture);
	void set(int direction, const  Vector2f& a);
	void draw(RenderWindow& window);
	void move(Window& window);
	bool checkForPosition();
	FloatRect getGlobalBounds();
};