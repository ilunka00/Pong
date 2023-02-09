#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include "view.cpp"
#include "image.cpp"
#include "stats.cpp"
#include "soundpad.cpp"
#include "controller.cpp"


using namespace sf;

class Game
{
private:
	Controller controller;
	sf::Vector2f ballDirection;
	Statistics stats;
	snd::Soundpad sounds; 

public:
	Game()
	{
		sounds.loadSounds();
		controller = Controller();
		stats = Statistics();
		ballDirection.x = 0.f;
		ballDirection.y = 0.f;
	}
	void setup()
	{
		sounds.playMusic();
		controller.setup();
		stats.setup();
	}
	void update(sf::RenderWindow& window)
	{
		if(stats.getScoreBot() == 5 || stats.getScorePlayer() == 5)
			window.close();
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();
			if(event.key.code == Keyboard::Space)
			{
				if(ballDirection.x == 0)
				{
					srand(time(NULL));
					ballDirection.x = 1;
					ballDirection.y = rand()%3+1;
				}
			}
			else if(event.type == Event::KeyPressed)
				controller.movePlayerPaddle(event.key.code);
		}
		window.clear(Color::Black);

		controller.drawAll(window, stats);
		if(ballDirection.x == 0)
			controller.drawPauseMenu(window);
	}
	void moveBall()
	{
		float ballPosX = controller.getAllObjects().getBallImage().getCenterX();
		float ballPosY = controller.getAllObjects().getBallImage().getCenterY();
		if (ballPosY < 15)
		{
			if(ballDirection.y < 0)
			{
				sounds.borderHitSound();
				ballDirection.y *= -1;
			}
		}
		if (ballPosY > 385)
		{
			if(ballDirection.y > 0)
			{
				sounds.borderHitSound();
				ballDirection.y *= -1;
			}
		}
		if (ballPosX > 630)
		{
			float paddlePosY = controller.getAllObjects().getBotPaddleImage().getCenterY();
			if (paddleHit(ballPosY, paddlePosY))
			{
				sounds.paddleHitSound();
				if(ballDirection.x > 0)
					ballDirection.x *= -1;
			}
			else
			{
				goal(true);
			}
		}
		if (ballPosX < 60)
		{
			float paddlePosY = controller.getAllObjects().getPlayerPaddleImage().getCenterY();
			if(paddleHit(ballPosY, paddlePosY))
			{
				sounds.paddleHitSound();
				if(ballDirection.x < 0)
					ballDirection.x *= -1;
			}
			else
			{
				goal(false);
			}
		}
		controller.moveBall(ballDirection);
	}

	void moveBot()
	{
		controller.moveBotPaddle();
	}
	bool paddleHit(float ballPosY, float paddlePosY)
	{
		if(ballPosY <= paddlePosY + 45 && ballPosY >= paddlePosY - 45)
			return true;
		else
			return false;
	}
	void goal(bool playerGoal) 
	{
		sounds.goalSound();

		if (playerGoal)
		{
			stats.botGoal();
			controller.setup();
			ballDirection.x = 0;
			ballDirection.y = 0;
		}
		else
		{
			stats.playerGoal();
			controller.setup();
			ballDirection.x = 0;
			ballDirection.y = 0;
		}
	}
};
#endif