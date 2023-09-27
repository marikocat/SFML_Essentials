#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main()
{
	sf::Window window(sf::VideoMode(640, 480), "Music");
	sf::Music music;
	if (!music.openFromFile("Hunter.flac"))
		return -1;
	//music.setVolume(10);
	music.setPitch(0.5);
	music.play();

	while (window.isOpen())
	{

	}

	return 0;
}