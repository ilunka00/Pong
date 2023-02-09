#ifndef MODEL
#define MODEL
#include "ballModel.cpp"
#include "botPaddleModel.cpp"
#include "playerPaddleModel.cpp"
#include "image.cpp"
#include <SFML/Graphics.hpp>
class Model : public BallModel, public BotPaddleModel, public PlayerPaddleModel
{
public:
	Model() 
	{
		ballModel.loadFromFile("ball.png");
		botPaddleModel.loadFromFile("paddle.png");
		playerPaddleModel.loadFromFile("paddle.png");
		ballModel.setCenterX(350);
		ballModel.setCenterY(200);
		ballModel.setPosition(350, 200);
		botPaddleModel.setPosition(640, 200);
		playerPaddleModel.setPosition(30, 200);
	}
	void setup()
	{
		ballModel.loadFromFile("ball.png");
		botPaddleModel.loadFromFile("paddle.png");
		playerPaddleModel.loadFromFile("paddle.png");
		ballModel.setCenterX(350);
		ballModel.setCenterY(200);
		ballModel.setPosition(350-14, 200-15);
		botPaddleModel.setPosition(640, 200-45);
		playerPaddleModel.setPosition(30, 200-45);
	}
	};
#endif