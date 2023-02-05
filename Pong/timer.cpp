#ifndef TIMER
#define TIMER
#include <SFML/Graphics.hpp>

class Timer
{
private:
	sf::Clock clock;
	float timer, delay;

public:
	Timer()
	{
		clock = sf::Clock();
		timer = 0;
		delay = 0;
	}
	void setTimer(float secs)
	{
		timer = secs;
	}
	float getTimer()
	{
		return timer;
	}
	float getDelay()
	{
		return delay;
	}

	void increaseTimer()
	{
		timer += clock.getElapsedTime().asSeconds();
		clock.restart();
	}
	void setDelay(float newDelay)
	{
		delay = newDelay;
	}
};
#endif