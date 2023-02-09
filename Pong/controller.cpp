#ifndef CONTROLLER
#define CONTROLLER
#include "model.cpp"
#include "view.cpp"
#include <SFML/Graphics.hpp>

class Controller
{
private:
	Model allObjects;
	mvcV::View display;

public:
	Controller()
	{
		allObjects = Model();
		display = mvcV::View();
	}
	void setup()
	{
		allObjects.setup();
	}
	void drawAll(sf::RenderWindow& window, Statistics& gameStats)
	{
		display.drawAllObjects(window, allObjects, gameStats);
	}
	void drawPauseMenu(sf::RenderWindow& window)
	{
		display.drawPause(window);
	}
	void movePlayerPaddle(sf::Keyboard::Key keyPressed)
	{
		Image* paddleToMove = allObjects.getPlayerPaddleImageAddr();
		float paddlePosY = paddleToMove->getCenterY();
		float paddlePosX = paddleToMove->getCenterX();
		if(keyPressed == sf::Keyboard::Up)
		{
			if(paddlePosY > 40)
			{
				paddleToMove->setCenterY(paddlePosY - 5);
				paddleToMove->setSpritePosition(paddlePosX, paddlePosY - 5 - 45);
				allObjects.setImagePlayerPaddle(*paddleToMove);
			}
		}
		else if(keyPressed == sf::Keyboard::Down)
		{
			if(paddlePosY < 360)
			{
				paddleToMove->setCenterY(paddlePosY + 5);
				paddleToMove->setSpritePosition(paddlePosX, paddlePosY + 5 - 45);
				allObjects.setImagePlayerPaddle(*paddleToMove);
			}
		}
	}
	void moveBotPaddle()
	{
		Image* newBotImage = allObjects.getBotPaddleImageAddr();
		float botPosY = allObjects.getBotPaddleImage().getCenterY();
		float ballPosY = allObjects.getBallImage().getCenterY();
		float botPosX = allObjects.getBotPaddleImage().getCenterX();
		if(botPosY < ballPosY)
		{
			if(botPosY < 360)
				botPosY += 5;
		}
		else if(botPosY > ballPosY)
		{
			if(botPosY > 40)
				botPosY -= 5;
		}
		newBotImage->setCenterY(botPosY);
		newBotImage->setCenterX(botPosX);
		newBotImage->setSpritePosition(botPosX, botPosY - 45);
		allObjects.setImageBot(*newBotImage);
	}
	void moveBall(sf::Vector2f movementDirection)
	{
		Image* ball = allObjects.getBallImageAddr();
		float newBallPosX = ball->getCenterX() + movementDirection.x;
		float newBallPosY = ball->getCenterY() + movementDirection.y;
		ball->setCenterX(newBallPosX);
		ball->setCenterY(newBallPosY);
		ball->setSpritePosition(newBallPosX - 13, newBallPosY - 14);
		allObjects.setImageBall(*ball);
	}
	Model getAllObjects()
	{
		return allObjects;
	}
};
#endif