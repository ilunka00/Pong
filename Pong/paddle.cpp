#include <SFML/Graphics.hpp>
#include "image.cpp"

class Paddle:public Image {

public:
	Paddle() {
		Img.loadFromFile("paddle.png");
		Sprite = sf::Sprite(Img);
	}
};