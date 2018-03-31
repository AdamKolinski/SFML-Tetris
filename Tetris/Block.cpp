#include "stdafx.h"
#include "Block.h"


Block::Block(int n, int t_X, int t_Y)
{
	this->shapeNumber = n;
	this->xPos = t_X;
	this->yPos = t_Y;
	shape.setFillColor(Color::White);
	shape.setSize(Vector2f(30.0f, 30.0f));
	//shape.setOrigin(shape.getSize().x/2.0f, shape.getSize().y / 2.0f);
}


void Block::moveBlock()
{
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 2; j++) {

		}
	}
}

void Block::drawBlock(sf::RenderWindow& window)
{
	int xPos = this->xPos;
	int yPos = this->yPos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (this->shapesArray[this->shapeNumber][j+2*i] == 1) {
				shape.setPosition(xPos, yPos);
				window.draw(shape);
			}
			xPos += 32;
		}
		xPos = this->xPos;
		yPos += 32;
	}
}

void Block::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}