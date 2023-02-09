#ifndef STATS
#define STATS
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
		botSprite.setPosition(225, 5);
		playerSprite.setPosition(400, 5);
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
		botSprite.setPosition(225, 5);
		scoreBot++;
	}

	void playerGoal()
	{
		playerTexture.loadFromFile(names[scorePlayer]);
		playerSprite = sf::Sprite(playerTexture);
		playerSprite.setPosition(400, 5);
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
	void setup()
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
		botSprite.setPosition(225, 5);
		playerSprite.setPosition(400, 5);
	}
};
#endif