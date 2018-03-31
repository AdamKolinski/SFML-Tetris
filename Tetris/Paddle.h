#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_x, float t_y);
	Paddle() = delete;
	RectangleShape shape;

	void update();
	float left();
	float right();
	float top();
	float bottom();

private:
	
	const float paddleWidth{ 100.0f };
	const float paddleHeight{ 5.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity, 0 };
	void draw(RenderTarget& target, RenderStates state) const override;
};

