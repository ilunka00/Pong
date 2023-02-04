#include <SFML/Graphics.hpp>
//#include <iostream>
#include "ball.cpp"
#include "paddle.cpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(700, 400), "Pong");
	Ball ball;
	Paddle paddleA;
	int ballCenterX = 336, ballCenterY = 185;
	int paddleAx = 30, paddleAy = 155;
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
			}
		}
		ball.setPosition(ballCenterX, ballCenterY);
		paddleA.setPosition(paddleA.getCenterX(), paddleA.getCenterY() - 45);
		window.clear(Color::Black);
		window.draw(paddleA.getSprite());
		window.draw(ball.getSprite());
		window.display();
	}

	return 0;
}