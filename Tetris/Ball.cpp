#include "stdafx.h"
#include "Ball.h"

using namespace std;

Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Ball::update() {
	shape.move(this->velocity);

	if (this->left() < 0) this->velocity.x = ballVelocity;
	else if (this->right() > 800) this->velocity.x = -ballVelocity;

	if (this->top() < 0) this->velocity.y = ballVelocity;
	else if (this->bottom() > 600) this->velocity.y = -ballVelocity;
}	

void Ball::moveUp() {
	this->velocity.y = -ballVelocity;
	printf("Moving up!");
	
}

float Ball::left() {
	return this->shape.getPosition().x - shape.getRadius();
}
float Ball::right() {
	return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top() {
	return this->shape.getPosition().y - shape.getRadius();
}
float Ball::bottom() {
	return this->shape.getPosition().y + shape.getRadius();
}