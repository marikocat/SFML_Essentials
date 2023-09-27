#include <SFML/Graphics.hpp>
#include "AssetManager.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Camera");
	AssetManager manager;

	auto wSize = window.getSize();
	View view(FloatRect(0, 0, wSize.x, wSize.y));

	// The view is centered around the world point (0; 0)
	view.setCenter(Vector2f(0, 0));

	// Initialize view
	window.setView(view);

	Vector2f spriteSize = Vector2f(32, 32);
	Sprite sprite(AssetManager::GetTexture("myTexture.png"));
	sprite.setOrigin(spriteSize * 0.5f); // Sprite origin at it's center
	sprite.setTextureRect(IntRect(0, 0, spriteSize.x, spriteSize.y));

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		// Update logic
		//view.setCenter(sprite.getPosition());
		//window.setView(view);

		window.clear();
		window.draw(sprite);
		window.display();
	}
}