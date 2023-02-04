#include <SFML/Graphics.hpp>
#include "image.cpp"
#include "timer.cpp"
#include "Paddle.cpp"

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

	void restart() {
		centerX = 350;
		centerY = 200;
		speedX = DEFAULT_SPEED;
		speedY = DEFAULT_SPEED;
#undef START
	}

	void start() {
		srand(time(NULL));
		setDelay(0.015);
		speedX = rand() % 3 + 1;
		speedY = rand() % 3 + 1;
	}
	
	void moveBall() {
		centerX += speedX;
		centerY += speedY;
	}
	int getSpeedX() {
		return speedX;
	}
	int getSpeedY() {
		return speedY;
	}
	void setSpeedX(int a) {
		speedX = a;
	}
	void setSpeedY(int a) {
		speedY = a;
	}

	bool paddleHit(Paddle paddle) {
		if (centerY >= paddle.getCenterY() - 45 && centerY <= paddle.getCenterY() + 45)
			return true;
		else return false;
	}
};