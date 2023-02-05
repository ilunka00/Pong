#ifndef PADDLE
#define PADDLE

#include "image.cpp"
#include <SFML/Graphics.hpp>

class Paddle : public Image
{

public:
	Paddle()
	{
		Img.loadFromFile("paddle.png");
		Sprite = sf::Sprite(Img);
		centerX = 30;
		centerY = 200;
	}
	void move(sf::Keyboard::Key key)
	{
		if(key == sf::Keyboard::Key::Up)
		{
			if(centerY > 40)
				centerY -= 5;
		}
		else if(key == sf::Keyboard::Key::Down)
		{
			if(centerY < 360)
				centerY += 5;
		}
	}
};

#endif