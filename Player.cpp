#include "Player.h"
Player::Player() {
	texture.loadFromFile("player.png");
	sprite.move(WindowW/2, WindowH - 50);
	sprite.setTexture(texture);
	sprite.setScale(50 / sprite.getLocalBounds().width, 50 / sprite.getLocalBounds().height);
}
void Player::move(float x, Window& window, float y ) {
	if ((sprite.getPosition().x < 0 + x && x < 0) || (sprite.getPosition().x > window.getSize().x - 50.0 - x && x > 0))
		return;
	sprite.move(x, y);
}
void Player::shoot(Bullet& a) {
	a.set(-1, sprite.getPosition());
}
bool Player::checkForHit(Bullet& a) {
	return a.getGlobalBounds().intersects(sprite.getGlobalBounds());
}
void Player::draw(RenderWindow& window) {
	window.draw(sprite);
}