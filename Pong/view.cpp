#ifndef VIEW
#define VIEW
#include "model.cpp"
#include "stats.cpp"
#include <SFML/Graphics.hpp>
namespace mvcV //mvcView
{
class View
{
public:
	void drawAllObjects(sf::RenderWindow& window, Model& objectToDraw, Statistics& gameStats)
	{
		Image* ballToDraw = objectToDraw.getBallImageAddr();
		Image* playerPaddleToDraw = objectToDraw.getPlayerPaddleImageAddr();
		Image* botPaddleToDraw = objectToDraw.getBotPaddleImageAddr();
		window.draw(ballToDraw->getSprite());
		window.draw(playerPaddleToDraw->getSprite());
		window.draw(botPaddleToDraw->getSprite());
		window.draw(gameStats.getSpriteBot());
		window.draw(gameStats.getSpritePlayer());
	}
	void drawPause(sf::RenderWindow& window)
	{
		sf::Texture start1, arrows1;
		arrows1.loadFromFile("arrows.png");
		start1.loadFromFile("start.png");
		sf::Sprite start = sf::Sprite(start1);
		sf::Sprite arrows = sf::Sprite(arrows1);
		arrows.setPosition(75, 275);
		start.setPosition(175, 75);
		window.draw(start);
		window.draw(arrows);
	}
};
} // namespace mvcV
#endif // !VIEW
