#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 1000), "SFML Works!");
	Texture texture;
	texture.loadFromFile("C:\\dev\\Pong\\Pong\\ball.png");
	Sprite sprite;
	sprite.setTexture(texture, true);
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{

			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		window.clear(Color::Black);
		window.draw(sprite);
		// Отрисовка окна	
		window.display();
	}

	return 0;
}