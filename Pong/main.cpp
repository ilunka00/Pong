#include <SFML/Graphics.hpp>
#include "ball.cpp"
#include "paddle.cpp"
#include "bot.cpp"



using namespace sf;

int main()
{
	RenderWindow window(VideoMode(700, 400), "Pong");
	Ball ball;
	ball.setCenterY(370);
	Paddle paddleA;
	Bot bot;

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
					ball.start();
				}
			}
		}

		//logic
		bot.setTimer(bot.getTimer() + bot.getClock()->getElapsedTime().asSeconds());
		bot.getClock()->restart();
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
		window.draw(paddleA.getSprite());
		window.draw(ball.getSprite());
		window.draw(bot.getSprite());
		window.display();
	}

	return 0;
}