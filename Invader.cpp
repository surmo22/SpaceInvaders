#include "Invader.h"
Invader::Invader(float& x, float& y, Texture& texture) {

	sprite.setPosition(x, y);
	sprite.setTexture(texture);
	sprite.setScale(40 / sprite.getLocalBounds().width, 40 / sprite.getLocalBounds().height);
}
void Invader::move(float x, Window& window, float y) {
	sprite.move(x, y);
}
void Invader::shoot(Bullet& a) { 
	a.set(1, sprite.getPosition());
}
void Invader::draw(RenderWindow& window) {
	window.draw(sprite);
}
const sf::Vector2f& Invader::getPos() {
	return sprite.getPosition();
}
FloatRect Invader::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
