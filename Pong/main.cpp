#include <SFML/Graphics.hpp>
#include "ball.cpp"
#include "paddle.cpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(700, 400), "Pong");
	Ball ball;
	Paddle paddleA;
	int centerX = 336, centerY = 185;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
		ball.setPosition(centerX, centerY);
		paddleA.setPosition(30, 155);
		window.clear(Color::Black);
		window.draw(paddleA.getSprite());
		window.draw(ball.getSprite());
		window.display();
	}

	return 0;
}