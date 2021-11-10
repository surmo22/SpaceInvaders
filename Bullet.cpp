#include "Bullet.h"

Bullet::Bullet(Texture& texture) {
	sprite.setTexture(texture);
	sf::RectangleShape rectangle;
	direction = 0;
	sprite.setScale(25 / sprite.getLocalBounds().width, 15 / sprite.getLocalBounds().height);
}
void Bullet::set(int direction, const  Vector2f& a) {
	Vector2f b = a;
	b.x += 31;
	sprite.setPosition(b);
	this->direction = direction;
	if (direction == 1) {
		sprite.rotate(-90);
	}
	else {
		sprite.rotate(90);
	}
}
void Bullet::draw(RenderWindow& window) {
	window.draw(sprite);
}
void Bullet::move(Window& window) {
	speed = (float)window.getSize().y / 4000;
	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (direction * speed));
}
bool Bullet::checkForPosition() {
	if (sprite.getPosition().y <= 0 || sprite.getPosition().y >= WindowH) {
		return 1;
	}
	return 0;
}
FloatRect Bullet::getGlobalBounds() {
	return sprite.getGlobalBounds();
}