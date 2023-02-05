#ifndef IMAGECPP
#define IMAGECPP

#include <SFML/Graphics.hpp>

class Image
{
protected:
	sf::Texture Img;
	sf::Sprite Sprite;
	int centerX, centerY;

public:
	void setPosition(int a, int b)
	{
		Sprite.setPosition(a, b);
	}
	sf::Texture getTexture()
	{
		return Img;
	}
	sf::Sprite getSprite()
	{
		return Sprite;
	}
	int getCenterX()
	{
		return centerX;
	}
	int getCenterY()
	{
		return centerY;
	}
	void setCenterY(int y)
	{
		centerY = y;
	}
	void setCenterX(int x)
	{
		centerX = x;
	}
	void loadFromFile(std::string path)
	{
		Img.loadFromFile(path);
		Sprite = sf::Sprite(Img);
	}
};

#endif