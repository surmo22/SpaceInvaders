#pragma once
#include "InvadersManager.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>
#include <sstream>
class Game {
	sf::RenderWindow window;
	Player player;
	InvadersManager invader_manager;
	Texture bullet;
	Texture backgroundTexture;
	Sprite BackgroundSprite;
	std::vector<Bullet> bullets;
	std::vector<Bullet> bulletsForPlayer;
	Font font;
	Text text;
	float x = 0;
	int ratefire = 0;
	int rateFireInvaders = 3000;
	int score = 0;
public:
	Game();
	void defaultCheck();
	void drawObjects();
	void start();
};
