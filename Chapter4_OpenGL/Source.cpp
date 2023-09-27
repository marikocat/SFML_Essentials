#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace sf;

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	settings.antialiasingLevel = 2;
	sf::Window window(sf::VideoMode(640, 480), "OpenGL", sf::Style::Default, settings);

	const auto& wSettings = window.getSettings();
	std::cout << "depthBits: " << wSettings.depthBits << std::endl;
	std::cout << "stencilBits: " << wSettings.stencilBits << std::endl;
	std::cout << "antialiasingLevel: " << wSettings.antialiasingLevel << std::endl;
	std::cout << "version: " << wSettings.majorVersion << "." << wSettings.minorVersion << std::endl;

	//sf::RenderWindow rWindow(sf::VideoMode(640, 480), "OpenGL", sf::Style::Default);

	// Window is ready to receive OpenGL calls here

	while (window.isOpen())
	{
		// Game loop
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();
		}

		// Update frame

		// Set red clear color;
		glClearColor(1, 0, 0, 1);
		// Clear the screen and the depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render things here

		// We have to save and restore the OpenGL states
		// each time we switch between rendering with SFMLand rendering with OpenGL explicitly.
		// 
		// Draw shape using OpenGL

		//rWindow.pushGLStates();
		// Draw shape using SFML
		//rWindow.popGLStates();

		// Continue drawing using OpenGL

		// SwapBuffers
		window.display();
	}

	return 0;
}