#include <SFML/Graphics.hpp>
#include "AssetManager.h"

Sprite createSprite(string const& filename)
{
	Texture texture;
	texture.loadFromFile(filename);
	return Sprite(texture);
}

int main()
{
	RenderWindow window(
		VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),
		"AssetManager");
	AssetManager manager;

	// Sprite sprite = createSprite("mapleLeaf.png");
	Sprite sprite = Sprite(AssetManager::GetTexture("mapleLeaf.png"));
	Sprite sprite2 = Sprite(AssetManager::GetTexture("mapleLeaf.png"));
	sprite2.move(AssetManager::GetTexture("mapleLeaf.png").getSize().x, 0);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(sprite);
		window.draw(sprite2);
		window.display();
	}
}