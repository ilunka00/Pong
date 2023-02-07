#ifndef VIEW
#define VIEW
#include <SFML/Graphics.hpp>
#include "model.cpp"
namespace mvcView
{
class View
{
public:
	void drawAnObject(sf::RenderWindow& window, Model objectToDraw)
	{
		window.draw(objectToDraw.getSprite());
	}
};
} // namespace mvcView
#endif // !VIEW
