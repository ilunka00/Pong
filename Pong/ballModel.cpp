#ifndef BALL_MODEL
#define BALL_MODEL
#include "image.cpp"
class BallModel
{
protected:
	Image ballModel;

public:
	BallModel()
	{
		ballModel.loadFromFile("ball.png");
		ballModel.setCenterX(350);
		ballModel.setCenterY(200);
		ballModel.setSpritePosition(350, 200);
	}
	Image getBallImage()
	{
		return ballModel;
	}
	Image* getBallImageAddr()
	{
		return &ballModel;
	}
	void setImageBall(Image newBall)
	{
		ballModel = newBall;
	}
};
#endif