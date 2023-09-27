#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"

int main()
{
	sf::Window window(sf::VideoMode(640, 480), "Audio");
	AssetManager manager;

	//sf::SoundBuffer sBuffer;
	//if (!sBuffer.loadFromFile("mySound.ogg"))
	//	return -1; // Failed to load

	//sf::Sound sound(sBuffer);

	sf::Sound sound(AssetManager::GetSoundBuffer("Hunter.flac"));
	sound.play();

	while (window.isOpen())
	{
		// Game loop
	}

	return 0;
}