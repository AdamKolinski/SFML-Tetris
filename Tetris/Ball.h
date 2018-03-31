#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Ball : public sf::Drawable
{
public:
	Ball(float t_X, float t_Y);
	Ball() = delete;
	~Ball() = default;

	CircleShape shape;
	const float ballVelocity{ 3.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };

	void update();
	void moveUp();

	float left();
	float right();
	float top();
	float bottom();
private:
	
	const float ballRadius{6.0f};
	
	
	void draw(RenderTarget& target, RenderStates state) const override;
};

