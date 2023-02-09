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
	//Texture start1, arrows1;
	//arrows1.loadFromFile("arrows.png");
	//start1.loadFromFile("start.png");
	//Sprite start = Sprite(start1);
	//Sprite arrows = Sprite(arrows1);
	//arrows.setPosition(75, 275);
	//start.setPosition(175, 75);
	//Ball ball;
	//Paddle paddleA;
	//Bot bot;
	//Statistics stats;
	//int speedX = 1, speedY = 1;
	//SoundBuffer buf;
	//Sound sound;
	//stats.setPosition();
	//Music mTheme;
	//if(!mTheme.openFromFile("music.wav"))
	//	return -1;
	//mTheme.play();

	//while(window.isOpen())
	//{
	//	Event event;
	//	while(window.pollEvent(event))
	//	{
	//		if(event.type == Event::Closed)
	//			window.close();
	//		if(event.type == Event::KeyPressed)
	//		{
	//			if(event.key.code == Keyboard::Up)
	//				paddleA.move(Keyboard::Up);
	//			else if(event.key.code == Keyboard::Down)
	//				paddleA.move(Keyboard::Down);
	//			else if(event.key.code == Keyboard::Space)
	//			{
	//				if(ball.getSpeedX() == 0)
	//				{
	//					ball.start();
	//					speedX = ball.getSpeedX();
	//					speedY = ball.getSpeedY();
	//				}
	//			}
	//		}
	//	}

	//	// logic for ball
	//	ball.increaseTimer();
	//	if(ball.getTimer() >= ball.getDelay())
	//	{
	//		ball.moveBall();
	//		ball.setTimer(0);
	//	}
	//	if(ball.getCenterY() < 20)
	//	{
	//		if (ball.getSpeedY() != speedY)
	//		{
	//			buf.loadFromFile("sideHit.wav");
	//			sound = Sound(buf);
	//			sound.play();
	//		}
	//		ball.setSpeedY(speedY);
	//	}
	//	else if(ball.getCenterY() > 380)
	//	{
	//		if(ball.getSpeedY() != -speedY)
	//		{
	//			buf.loadFromFile("sideHit.wav");
	//			sound = Sound(buf);
	//			sound.play();
	//		}
	//		ball.setSpeedY(-speedY);
	//	}
	//	if(ball.getCenterX() < 70)
	//	{
	//		if(ball.paddleHit(paddleA))
	//		{
	//			if(ball.getSpeedY() != speedX)
	//			{
	//				buf.loadFromFile("paddlehit.wav");
	//				sound = Sound(buf);
	//				sound.play();
	//			}
	//			ball.setSpeedX(speedX);
	//		}
	//		else
	//		{
	//			ball.restart();
	//			stats.playerGoal();
	//			stats.setPosition();
	//			buf.loadFromFile("goal.wav");
	//			sound = Sound(buf);
	//			sound.play();
	//			if(stats.getScorePlayer() == 5)
	//			{
	//				return 0;
	//			}
	//		}
	//	}
	//	else if(ball.getCenterX() > 632)
	//	{
	//		if(ball.paddleHit(bot))
	//		{
	//			if(ball.getSpeedY() != -speedX)
	//			{
	//				buf.loadFromFile("paddlehit.wav");
	//				sound = Sound(buf);
	//				sound.play();
	//			}
	//			ball.setSpeedX(-speedX);
	//		}
	//		else
	//		{
	//			ball.restart();
	//			stats.botGoal();
	//			stats.setPosition();
	//			buf.loadFromFile("goal.wav");
	//			sound = Sound(buf);
	//			sound.play();
	//			if(stats.getScoreBot() == 5)
	//			{
	//				return 0;
	//			}
	//		}
	//	}

	//	// logic for bot
	//	bot.increaseTimer();
	//	if(bot.getTimer() >= bot.getDelay())
	//	{
	//		bot.botMoves(ball.getCenterY());
	//		bot.setTimer(0);
	//	}

	//	// positioning
	//	ball.setPosition(ball.getCenterX() - 14, ball.getCenterY() - 15);
	//	paddleA.setPosition(paddleA.getCenterX(), paddleA.getCenterY() - 45);
	//	bot.setPosition(bot.getCenterX(), bot.getCenterY() - 45);

	//	// draw
	//	window.clear(Color::Black);
	//	window.draw(stats.getSpriteBot());
	//	window.draw(stats.getSpritePlayer());
	//	window.draw(paddleA.getSprite());
	//	window.draw(ball.getSprite());
	//	window.draw(bot.getSprite());
	//	//view.drawAnObject(window, ball.getModel());
	//	if(ball.getSpeedX() == 0)
	//	{
	//		window.draw(start);
	//		window.draw(arrows);
	//	}
	//	window.display();
	//}
	Game game;
	Clock ballClock,botClock;
	float a = 0.f;
	float b = 0.f;
	game.setup();
	while (window.isOpen())
	{
		game.update(window);
		a += ballClock.getElapsedTime().asSeconds();
		ballClock.restart();
		b += botClock.getElapsedTime().asSeconds();
		botClock.restart();
		if(a > 0.025)
		{
			a = 0.f;
			game.moveBall();
		}
		if (b > 0.1)
		{
			b = 0.f;
			game.moveBot();
		}
		window.display();
	}
	return 0;
}

