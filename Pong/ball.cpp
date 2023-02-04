#include <SFML/Graphics.hpp>
#include <iostream>
#include "image.cpp"
#define DEFAULT_SPEED 1

class Ball:public Image {
private:
	int speedX;
	int speedY;
public:
	Ball() {
		speedX = DEFAULT_SPEED;
		speedX = DEFAULT_SPEED;
		Img.loadFromFile("ball.png");
		Sprite = sf::Sprite(Img);
		centerX = 350;
		centerY = 200;
	}

	void start() {
		srand(time(NULL));
		speedX = rand() % 3 + 1;
		speedY = rand() % 3 + 1;

	}


};