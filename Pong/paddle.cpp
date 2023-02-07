#ifndef PADDLE
#define PADDLE

#include "image.cpp"
#include <SFML/Graphics.hpp>

class Paddle
{
protected:
	Image paddleModel;

public:
	Paddle()
	{
		paddleModel.loadFromFile("paddle.png");
		paddleModel.setCenterX(30);
		paddleModel.setCenterY(200);
	}
	void setPosition(int newPositionX, int newPositionY)
	{
		paddleModel.setPosition(newPositionX, newPositionY);
	}
	int getCenterY() 
	{ 
		return paddleModel.getCenterY();
	}
	int getCenterX()
	{
		return paddleModel.getCenterX();
	}
	sf::Sprite getSprite()
	{
		return paddleModel.getSprite();
	}
	void move(sf::Keyboard::Key key)
	{
		int oldCenterY = paddleModel.getCenterY();
		if(key == sf::Keyboard::Key::Up)
		{
			if(paddleModel.getCenterY() > 40)
				paddleModel.setCenterY(oldCenterY - 5);
		}
		else if(key == sf::Keyboard::Key::Down)
		{
			if(paddleModel.getCenterY() < 360)
				paddleModel.setCenterY(oldCenterY + 5);
		}
	}
};

#endif