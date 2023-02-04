#include "paddle.cpp"
#include <SFML/Graphics.hpp>
#include "timer.cpp"

class Bot :public Paddle,public Timer {


public:
	Bot() {
		centerX = 640;
	}


	void botMoves(int ballCenterY) {
		if (ballCenterY > centerY) move(sf::Keyboard::Key::Down);
		else if (ballCenterY < centerY)move(sf::Keyboard::Key::Up);
	}

	
};