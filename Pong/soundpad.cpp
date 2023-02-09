#ifndef SOUNDPAD
#define SOUNDPAD
#include <SFML/Audio.hpp>
namespace snd
{
class Soundpad
{
private:
	sf::SoundBuffer goal, paddleHit, borderHit;
	sf::Sound goalS, paddleHitS, borderHitS;
	sf::Music ost;

public:
	Soundpad()
	{
		goal.loadFromFile("goal.wav");
		paddleHit.loadFromFile("paddlehit.wav");
		borderHit.loadFromFile("sideHit.wav");
		goalS.setBuffer(goal);
		paddleHitS.setBuffer(paddleHit);
		borderHitS.setBuffer(borderHit);
		ost.openFromFile("music.wav");
	}
	void loadSounds() 
	{
		goal.loadFromFile("goal.wav");
		paddleHit.loadFromFile("paddlehit.wav");
		borderHit.loadFromFile("sideHit.wav");
		goalS.setBuffer(goal);
		paddleHitS.setBuffer(paddleHit);
		borderHitS.setBuffer(borderHit);
		ost.openFromFile("music.wav");
	}
	void goalSound()
	{
		goalS.play();
	}
	void paddleHitSound()
	{
		paddleHitS.play();
	}
	void borderHitSound()
	{
		borderHitS.play();
	}
	void playMusic()
	{
		ost.play();
	}
};
} // namespace snd
#endif