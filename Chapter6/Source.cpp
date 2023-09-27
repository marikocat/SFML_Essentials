#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderTexture rTexture;
	rTexture.create(64, 64);

	sf::CircleShape circle(16);

	// Render routine - clear -> draw -> display
	rTexture.clear(sf::Color::Blue);

	rTexture.draw(circle);

	rTexture.display();

	// RenderTexture::getTexture() gets a ref to the Texture object
	sf::Sprite sprite(rTexture.getTexture());

	sf::RenderWindow window(sf::VideoMode(640, 480), "RenderTexture");

	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		window.display();
	}
}