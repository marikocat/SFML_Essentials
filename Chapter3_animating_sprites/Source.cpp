#include <SFML/Graphics.hpp>
#include "AssetManager.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(
		VideoMode::getDesktopMode().width,
		VideoMode::getDesktopMode().height),
		"Animation");
	AssetManager manager;

	Vector2i spriteSize(32, 32);
	Sprite sprite(AssetManager::GetTexture("spriteSheet.png"));
	sprite.setTextureRect(IntRect(0, 0, spriteSize.x, spriteSize.y));

	int framesNum = 8;
	float animationDuration = 1; // 1 second

	Clock clock;
	Time elapsedTime;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		// Returns the elapsed time and restarts the clock
		Time deltaTime = clock.restart();


		// Accumulate time with each frame
		elapsedTime += deltaTime;
		float timeAsSeconds = elapsedTime.asSeconds();

		// Get the current animation frame
		int animFrame = static_cast<int>((timeAsSeconds / animationDuration) * framesNum) % framesNum;
		// Set the texture rectangle, depending on the frame
		sprite.setTextureRect(IntRect(animFrame * spriteSize.x, 0, spriteSize.x, spriteSize.y));

		window.clear();
		window.draw(sprite);
		window.display();
	}
}