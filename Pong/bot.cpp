#include "paddle.cpp"
#include <SFML/Graphics.hpp>

class Bot :public Paddle {
private:
	sf::Clock* clock;
	float timer, delay;

public:
	Bot() {
		timer = 0;
		delay = 0.1;
		centerX = 640;
		clock = new sf::Clock();
	}
	~Bot() {
		delete clock;
	}

	void botMoves(int ballCenterY) {
		if (ballCenterY > centerY) move(sf::Keyboard::Key::Down);
		else if (ballCenterY < centerY)move(sf::Keyboard::Key::Up);
	}

	void setTimer(float secs){
		timer = secs;
	}
	float getTimer() {
		return timer;
	}
	float getDelay() {
		return delay;
	}
	sf::Clock* getClock() {
		return clock;
	}
};