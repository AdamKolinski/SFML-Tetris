#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(int n, int r, int t_X, int t_Y);
	~Block() = default;

	RectangleShape shape;
	int shapeNumber;
	int rotation;
	int xPos = 0, yPos = 0;

	int shapesArray[7][16] = {
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0, //I

		0,0,0,0,
		1,0,0,0,
		1,1,0,0,
		0,1,0,0, //Z

		0,0,0,0,
		0,1,0,0,
		1,1,0,0,
		1,0,0,0, //S

		0,0,0,0,
		0,1,0,0,
		1,1,0,0,
		0,1,0,0, //T


		0,0,0,0,
		1,1,0,0,
		0,1,0,0,
		0,1,0,0, //L

		0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		1,1,0,0, //J

		0,0,0,0,
		0,0,0,0,
		1,1,0,0,
		1,1,0,0, //O
	};

	int shapesArrayR1[7][16] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		1,1,1,1, //I

		0,0,0,0,
		0,0,0,0,
		0,1,1,0,
		1,1,0,0, //Z

		0,0,0,0,
		0,0,0,0,
		1,1,0,0,
		0,1,1,0, //S

		0,0,0,0,
		0,0,0,0,
		0,1,0,0,
		1,1,1,0, //T


		0,0,0,0,
		0,0,0,0,
		0,0,1,0,
		1,1,1,0, //L

		0,0,0,0,
		0,0,0,0,
		1,0,0,0,
		1,1,1,0, //J

		0,0,0,0,
		0,0,0,0,
		1,1,0,0,
		1,1,0,0, //O
	};

	void moveBlock();
	void drawBlock(sf::RenderWindow& window);

private:

	void draw(RenderTarget& target, RenderStates state) const override;
};
