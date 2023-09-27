#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main()
{
	// sf::Window window(sf::VideoMode(300, 200), "The title");
	sf::Window window;
	sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize;
	sf::Uint32 style2 = sf::Style::Fullscreen;
	window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), 
		"The title", style);
	//sf::sleep(sf::seconds(5));

	window.setMouseCursorVisible(false);

	sf::String buffer;
	// Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::KeyPressed:
				// Change the title if the space is pressed
				if (event.key.code == sf::Keyboard::Key::Space)
				{
					window.setTitle("Space Pressed");
					cout << "Space Pressed\n";
				}
				break;
			case sf::Event::EventType::Closed:
				window.close();
				break;
			case sf::Event::EventType::TextEntered:
				// Add the character directly to the string
				buffer += event.text.unicode;
				break;
			case sf::Event::EventType::KeyReleased:
				// Change the title again if space is released
				if (event.key.code == sf::Keyboard::Key::Space)
				{
					window.setTitle("Space Released");
					cout << "Space Released\n";
				}
				// Close the window if the Escape key is released
				else if (event.key.code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
				else if (event.key.code == sf::Keyboard::Key::Return)
				{
					window.setTitle(buffer);
					buffer.clear();
				}
				break;
			}
		}
	}

	return 0;
}