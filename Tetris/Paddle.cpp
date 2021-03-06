#include "stdafx.h"
#include "Paddle.h"

Paddle::Paddle(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({this->paddleWidth, this->paddleHeight});
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->paddleWidth/2.f, this->paddleHeight/2.f);
}

void Paddle::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Paddle::update() {
	this->shape.move(this->velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::A) && this->left() > 0) {
		velocity.x = -paddleVelocity;
	} else if (Keyboard::isKeyPressed(Keyboard::Key::D) && this->right() < 800) {
		velocity.x = paddleVelocity;
	}
	else velocity.x = 0;
}

float Paddle::left() {
	return this->shape.getPosition().x - shape.getSize().x /2.f;
}
float Paddle::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Paddle::top() {
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Paddle::bottom() {
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}