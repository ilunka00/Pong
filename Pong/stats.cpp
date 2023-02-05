#include "image.cpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Statistics
{
	std::vector<std::string> names;
	sf::Texture botTexture, playerTexture;
	sf::Sprite botSprite, playerSprite;
	int scorePlayer, scoreBot;

public:
	Statistics()
	{
		scoreBot = 0;
		scorePlayer = 0;
		names.push_back("one.png");
		names.push_back("two.png");
		names.push_back("three.png");
		names.push_back("four.png");
		names.push_back("five.png");
		botTexture.loadFromFile("zero.png");
		playerTexture.loadFromFile("zero.png");
		botSprite = sf::Sprite(botTexture);
		playerSprite = sf::Sprite(playerTexture);
	}

	int getScorePlayer()
	{
		return scorePlayer;
	}
	int getScoreBot()
	{
		return scoreBot;
	}

	void botGoal()
	{
		botTexture.loadFromFile(names[scoreBot]);
		botSprite = sf::Sprite(botTexture);
		scoreBot++;
	}

	void playerGoal()
	{
		playerTexture.loadFromFile(names[scorePlayer]);
		playerSprite = sf::Sprite(playerTexture);
		scorePlayer++;
	}

	sf::Sprite getSpriteBot()
	{
		return botSprite;
	}
	sf::Sprite getSpritePlayer()
	{
		return playerSprite;
	}
	void setPosition()
	{
		botSprite.setPosition(225, 5);
		playerSprite.setPosition(400, 5);
	}
};