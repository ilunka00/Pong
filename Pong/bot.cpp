#include "paddle.cpp"
#include "timer.cpp"
#include <SFML/Graphics.hpp>

class Bot : public Paddle, public Timer
{

public:
	Bot()
	{
		paddleModel.setCenterX(640);
		setDelay(0.1);
	}

	void botMoves(int ballCenterY)
	{
		if(ballCenterY > paddleModel.getCenterY())
			move(sf::Keyboard::Key::Down);
		else if(ballCenterY < paddleModel.getCenterY())
			move(sf::Keyboard::Key::Up);
	}
};