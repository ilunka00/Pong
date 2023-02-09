#include "game.cpp"
#include "model.cpp"
#include "stats.cpp"
#include "view.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


int main()
{
	RenderWindow window(VideoMode(700, 400), "Pong");
	Game game;
	Clock ballClock,botClock;
	float ballDelay = 0.f;
	float botDelay = 0.f;
	game.setup();
	while (window.isOpen())
	{
		ballDelay += ballClock.getElapsedTime().asSeconds();
		ballClock.restart();
		botDelay += botClock.getElapsedTime().asSeconds();
		botClock.restart();
		if(ballDelay > 0.01)
		{
			ballDelay = 0.f;
			game.moveBall();
		}
		if(botDelay > 0.1)
		{
			botDelay = 0.f;
			game.moveBot();
		}
		game.update(window);
		window.display();
	}
	return 0;
}

