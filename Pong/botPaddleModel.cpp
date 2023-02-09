#ifndef BOT_PADDLE_MODEL
#define BOT_PADDLE_MODEL
#include "image.cpp"
class BotPaddleModel
{
protected:
	Image botPaddleModel;

public:
	BotPaddleModel()
	{
		botPaddleModel.loadFromFile("paddle.png");
		botPaddleModel.setCenterX(640);
		botPaddleModel.setCenterY(200);
		botPaddleModel.setSpritePosition(640, 200);
	}
	Image getBotPaddleImage()
	{
		return botPaddleModel;
	}
	Image* getBotPaddleImageAddr()
	{
		return &botPaddleModel;
	}
	void setImageBot(Image newBotPaddle)
	{
		botPaddleModel = newBotPaddle;
	}
};
#endif