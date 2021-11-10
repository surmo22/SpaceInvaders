#include "Game.h"
Game::Game() {
	window.create(VideoMode(WindowW, WindowH), "Space invaders");
	font.loadFromFile("times.ttf");
	text.setString("DEFEAT");
	text.setCharacterSize(48);
	text.setFont(font);
	text.setStyle(Text::Bold);
	text.setPosition(Vector2f(WindowW / 2 - 80, WindowH / 2 - 80));
}
void Game::defaultCheck() {
	for (unsigned int i = 0; i < bullets.size(); i++) {
		bool z = bullets[i].checkForPosition();
		bool x = invader_manager.checkForHit(bullets[i], window);
		if ((z || x) && bullets.size() != 1) {
			score += 100;
			bullets.erase(bullets.begin() + i);
			break;
		}
		else if ((z || x) && bullets.size() == 1) {
			score += 100;
			bullets.clear();
			break;
		}
	}
	for (unsigned int i = 0; i < bulletsForPlayer.size(); i++) {
		bool z = bulletsForPlayer[i].checkForPosition();
		if ((z) && bulletsForPlayer.size() != 1) {
			bulletsForPlayer.erase(bulletsForPlayer.begin() + i);
			break;
		}
		else if ((z) && bulletsForPlayer.size() == 1) {
			bulletsForPlayer.clear();
			break;
		}
	}
}
void Game::drawObjects() {
	window.clear(Color::Blue);
	window.draw(BackgroundSprite);
	player.draw(window);
	for (auto& i : bullets) {
		i.draw(window);
	}
	for (auto& i : bulletsForPlayer) {
		i.draw(window);
	}
	invader_manager.draw(window);
}
void Game::start() {
	bool looseFlag2 = 0;
	bullet.loadFromFile("AA.png");
	backgroundTexture.loadFromFile("city.png");
	BackgroundSprite.setTexture(backgroundTexture);
	Vector2u size = backgroundTexture.getSize();
	BackgroundSprite.setPosition(0, 0);
	BackgroundSprite.setScale(WindowW / BackgroundSprite.getLocalBounds().width, WindowH / BackgroundSprite.getLocalBounds().height);
	while (window.isOpen())
	{
		Bullet a(bullet);
		Bullet b(bullet);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Left) x = -(float)window.getSize().x/12000;
				else if (event.key.code == Keyboard::Right) x = (float)window.getSize().x / 12000;
				else if (event.key.code == Keyboard::Space) {
					if (ratefire == 0) {
						player.shoot(a);
						bullets.push_back(a);
						ratefire = 2500;
					}
				}
				else if (event.key.code == Keyboard::Escape) {
					window.close();
				}
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Right || event.key.code == Keyboard::Left) x = 0;
			}
		}
		player.move(x,window);
		if (rateFireInvaders == 0) {
			rateFireInvaders = 5000;
			invader_manager.fire(b);
			bulletsForPlayer.push_back(b);
		}
		for (auto& i : bullets) {
			i.move(window);
		}
		for (auto& i : bulletsForPlayer) {
			i.move(window);
			if (player.checkForHit(i)) {
				looseFlag2 = 1;
				break;
			}
		}
		defaultCheck();
		bool looseFlag = invader_manager.checkForLoose();
		if (looseFlag || looseFlag2) {
			std::ostringstream oss;
			oss << score;
			text.setString("DEFEAT\nScore =" + oss.str());
			window.clear(Color::Black);
			window.draw(text);
			window.display();
			continue;
		}
		invader_manager.move(window);
		drawObjects();
		window.display();
		if (ratefire > 0) ratefire -= 1;
		if (rateFireInvaders > 0) rateFireInvaders -= 1;

	}
}