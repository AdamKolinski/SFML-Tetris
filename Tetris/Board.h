#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Board : sf::Drawable
{
public:
	
	Board(int t_width, int t_height, int t_block_size);
	~Board() = default;

	int width, height, block_size;
	bool boardStates[10][18];
	
	void initializeBoard();
	RectangleShape shape;

	void drawBoard(RenderWindow& window);

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};

