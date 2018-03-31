#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(int n, int t_X, int t_Y);
	~Block() = default;

	RectangleShape shape;
	int shapeNumber;
	int xPos = 0, yPos = 0;

	int shapesArray[7][8] = {
		0,1,
		0,1,
		0,1,
		0,1, //I

		0,0,
		1,0,
		1,1,
		0,1, //Z

		0,0,
		0,1,
		1,1,
		1,0, //S

		0,0,
		0,1,
		1,1,
		0,1, //T


		0,0,
		1,1,
		0,1,
		0,1, //L

		0,0,
		0,1,
		0,1,
		1,1, //J

		0,0,
		0,0,
		1,1,
		1,1, //O
	};

	void moveBlock();
	void drawBlock(sf::RenderWindow& window);

private:

	void draw(RenderTarget& target, RenderStates state) const override;
};
