#include "Paddle.cpp"
#include "model.cpp"
#include "timer.cpp"
#include <SFML/Graphics.hpp>

#define DEFAULT_SPEED 0

class Ball : public Timer
{
private:
	Model ballModel;
	int speedX;
	int speedY;

public:
	Ball()
	{
		ballModel.loadFromFile("ball.png");
		speedX = DEFAULT_SPEED;
		speedY = DEFAULT_SPEED;
		ballModel.setCenterX(350);
		ballModel.setCenterY(200);
	}

	void restart()
	{
		ballModel.setCenterX(350);
		ballModel.setCenterY(200);
		speedX = DEFAULT_SPEED;
		speedY = DEFAULT_SPEED;
	}

	void start()
	{
		srand(time(NULL));
		setDelay(0.015);
		speedX = rand() % 3 + 1;
		speedY = rand() % 3 + 1;
	}

	void moveBall()
	{
		int oldBallCenterX = ballModel.getCenterX();
		int oldBallCenterY = ballModel.getCenterY();
		ballModel.setCenterX(oldBallCenterX+speedX);
		ballModel.setCenterY(oldBallCenterY+speedY);
	}
	sf::Sprite getSprite() 
	{
		return ballModel.getSprite();
	}
	int getSpeedX()
	{
		return speedX;
	}

	int getSpeedY()
	{
		return speedY;
	}

	void setSpeedX(int a)
	{
		speedX = a;
	}

	void setSpeedY(int a)
	{
		speedY = a;
	}
	void setPosition(int newPositionX,int newPositionY) 
	{
		ballModel.setPosition(newPositionX, newPositionY);
	}
	int getCenterX()
	{
		return ballModel.getCenterX();
	}
	int getCenterY()
	{
		return ballModel.getCenterY();
	}
	Model getModel() 
	{
		return ballModel;
	}
	bool paddleHit(Paddle paddle)
	{
		if(ballModel.getCenterY() >= paddle.getCenterY() - 45 &&
		   ballModel.getCenterY() <= paddle.getCenterY() + 45)
			return true;
		else
			return false;
	}
};