#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000, 1000), "SFML Works!");
	Texture texture;
	texture.loadFromFile("C:\\dev\\Pong\\Pong\\ball.png");
	Sprite sprite;
	sprite.setTexture(texture, true);
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{

			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		window.clear(Color::Black);
		window.draw(sprite);
		// ��������� ����	
		window.display();
	}

	return 0;
}