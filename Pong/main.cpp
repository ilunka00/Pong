#include <SFML/Graphics.hpp>
#include "ball.cpp"
#include "paddle.cpp"
#include "bot.cpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(700, 400), "Pong");
	Ball ball;
	Paddle paddleA;
	Bot bot;
	int speedX=1, speedY=1;
	int scorePlayer=0, scoreBot=0;

	Texture zero;
	zero.loadFromFile("zero.png");
	Sprite sprite=Sprite(zero);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up) paddleA.move(Keyboard::Up);
				else if (event.key.code == Keyboard::Down) paddleA.move(Keyboard::Down);
				else if (event.key.code == Keyboard::Space) {
#ifndef START
#define START
					ball.start();
					speedX = ball.getSpeedX();
					speedY = ball.getSpeedY();
#endif
				}
			}
		}


		//logic for ball
		ball.increaseTimer();
		if (ball.getTimer() >= ball.getDelay()) {
			ball.moveBall();
			ball.setTimer(0);
		}
		if (ball.getCenterY() < 20) ball.setSpeedY(speedY);
		else if(ball.getCenterY() > 380) ball.setSpeedY(-speedY);
		if (ball.getCenterX() < 50) {
			if (ball.paddleHit(paddleA)) ball.setSpeedX(speedX);
			else ball.restart(); //goal
		}
		else if( ball.getCenterX() > 632) {			
			if (ball.paddleHit(bot)) ball.setSpeedX(-speedX);
			else ball.restart();//goal
		}

		//logic for bot
		bot.increaseTimer();
		if (bot.getTimer() >= bot.getDelay()) {
			bot.botMoves(ball.getCenterY());
			bot.setTimer(0);
		}

		//positioning
		ball.setPosition(ball.getCenterX() - 14, ball.getCenterY()-15);
		paddleA.setPosition(paddleA.getCenterX(), paddleA.getCenterY() - 45);
		bot.setPosition(bot.getCenterX(), bot.getCenterY() - 45);

		//draw

		window.clear(Color::Black);
		window.draw(sprite);
		window.draw(paddleA.getSprite());
		window.draw(ball.getSprite());
		window.draw(bot.getSprite());
		window.display();
	}

	return 0;
}