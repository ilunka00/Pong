#ifndef imagecpp
#define imagecpp

#include <SFML/Graphics.hpp>

class Image {
protected:
	sf::Texture Img;
	sf::Sprite Sprite;
public:
	void setPosition(int a, int b) {
		Sprite.setPosition(a, b);
	}
	sf::Texture getTexture() {
		return Img;
	}
	sf::Sprite getSprite() {
		return Sprite;
	}
};

#endif