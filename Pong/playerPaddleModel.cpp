#ifndef PLAYER_PADDLE_MODEL
#define PLAYER_PADDLE_MODEL
#include "image.cpp"

class PlayerPaddleModel
{
protected:
	Image playerPaddleModel;

public:
	PlayerPaddleModel()
	{
		playerPaddleModel.loadFromFile("paddle.png");
		playerPaddleModel.setCenterX(30);
		playerPaddleModel.setCenterY(200);
		playerPaddleModel.setPosition(30, 200);
	}
	Image getPlayerPaddleImage()
	{
		return playerPaddleModel;
	}
	Image* getPlayerPaddleImageAddr()
	{
		return &playerPaddleModel;
	}
	void setImagePlayerPaddle(Image newPlayerPaddle)
	{
		playerPaddleModel = newPlayerPaddle;
	}
};
#endif