#include <SFML/Graphics.hpp>
#include "image.cpp"
#include "timer.cpp"
#define DEFAULT_SPEED 0

class Ball:public Image, public Timer {
private:
	int speedX;
	int speedY;
public:
	Ball() {
		speedX = DEFAULT_SPEED;
		speedY = DEFAULT_SPEED;
		Img.loadFromFile("ball.png");
		Sprite = sf::Sprite(Img);
		centerX = 350;
		centerY = 200;
	}

	void start() {
		srand(time(NULL));
		setDelay(0.1);
		speedX = rand() % 3 + 1;
		speedY = rand() % 3 + 1;
	}
	
	void moveBall() {
		centerX += speedX;
		centerY += speedY;
	}

};