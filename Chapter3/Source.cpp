#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "Clock");

	Time time = seconds(5) + milliseconds(100);
	if (time > seconds(5.09))
		std::cout << "It works\n";

	Clock clock;
	Time timePassed = clock.getElapsedTime();
	Time elapsedTime;
	Time deltaTime;
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		float dtAsSeconds = deltaTime.asSeconds();
		elapsedTime += deltaTime;

		if (elapsedTime > seconds(5))
		{
			window.close();
		}
	}
}