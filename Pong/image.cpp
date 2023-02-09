#ifndef IMAGE
#define IMAGE

#include <SFML/Graphics.hpp>


class Image
{
protected:
	sf::Texture img;
	sf::Sprite sprite;
	float centerX=0, centerY=0;

public:
	void setSpritePosition(int a, int b)
	{
		sprite.setPosition(a, b);
	}
	sf::Texture getTexture()
	{
		return img;
	}
	sf::Sprite getSprite()
	{
		return sprite;
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
		img.loadFromFile(path);
		sprite = sf::Sprite(img);
	}
};
#endif