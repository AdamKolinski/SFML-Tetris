#include "stdafx.h"
#include "Board.h"


Board::Board(int t_width, int t_height, int t_block_size)
{
	this->width = t_width;
	this->height = t_height;
	this->block_size = t_block_size;
	shape.setSize(Vector2f(block_size, block_size));
}

void Board::initializeBoard()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			boardStates[i][j] = 0;
		}
	}
}

void Board::drawBoard(RenderWindow& window) {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++)
		{
			shape.setFillColor(sf::Color(79, 195, 247));
			shape.setPosition(Vector2f((i*(block_size + 2))+2, (j*(block_size + 2))+2));
			if (boardStates[i][j] == 1) shape.setFillColor(sf::Color(229, 115, 115));
			window.draw(shape);
		}
	}
}

void Board::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}