#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Text");
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
		return -1;

	AssetManager manager;

	sf::Text text("Look at my awesome font.", AssetManager::GetFont("font.ttf"));
	text.setCharacterSize(30);

	sf::String someString;
	someString = "Hello.";

	text.setString(someString);
	text.setString("This is a normal string.");
	text.setString(L"This is a wide-char string. Привет.");
	text.setString(std::string("This is a normal string."));
	text.setString(std::wstring(L"This is a wide-char string. Привет."));

	text.setFillColor(sf::Color::Green);
	text.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);

	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.key.code == Keyboard::Key::Escape)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}