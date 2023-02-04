#include <SFML/Graphics.hpp>
#include "image.cpp"
#define DEFAULT_SPEED 5

class Ball:public Image {
private:
	int speed;

public:
	Ball() {
		speed = DEFAULT_SPEED;
		Img.loadFromFile("ball.png");
		Sprite = sf::Sprite(Img);
		centerX = 350;
		centerY = 200;
	}
	void setSpeed(int newSpeed) {
		if (newSpeed > 10 || newSpeed < 1) return;
		speed = newSpeed;
	}
	
};