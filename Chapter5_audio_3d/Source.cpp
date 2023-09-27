#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"

#define PI_RADIANS 3.1415f
#define PI_DEGREES 180.f

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Audio 3D");

	sf::Sprite heroSprite(AssetManager::GetTexture("myHero.png"));
	sf::Sprite zombie(AssetManager::GetTexture("zombie.png"));
	sf::Sound growl(AssetManager::GetSoundBuffer("growl.ogg"));

	while (window.isOpen())
	{
		sf::Vector2f heroPos = heroSprite.getPosition();
		sf::Listener::setPosition(heroPos.x, heroPos.y, 0);

		float heroRot = heroSprite.getRotation() * PI_RADIANS / PI_DEGREES;
		// Set the listener's direction from the hero's rotation
		sf::Listener::setDirection(std::cos(heroRot), std::sin(heroRot), 0);

		sf::Vector2f zombiePos = zombie.getPosition();
		growl.setPosition(zombiePos.x, zombiePos.y, 0);
	}
}