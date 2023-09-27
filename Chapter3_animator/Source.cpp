#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "AssetManager.h"

int main()
{
	RenderWindow window(
		VideoMode(VideoMode::getDesktopMode().width, 
		VideoMode::getDesktopMode().height),
		"Animator");
	AssetManager manager;

	Vector2i spriteSize(32, 32);
	Sprite sprite;

	Animator animator(sprite);

	// Idle animation with 8 frames @ 1 sec looping
	// Create an animation and get the reference to it
	auto& idleAnimation = animator.CreateAnimation("Idle", "spriteSheet.png", seconds(1), true);
	// Add frames to the animation
	idleAnimation.AddFrames(Vector2i(0, 0), spriteSize, 8);

	// IdleShort animation with 8 frames @ 0.5 sec looping
	auto& idleAnimationShort = animator.CreateAnimation("IdleShort", "spriteSheet.png", seconds(0.5f), true);
	idleAnimationShort.AddFrames(Vector2i(0, 0), spriteSize, 8);

	// IdleSmall animation with 5 frames @ 0.5 sec looping
	auto& idleAnimationSmall = animator.CreateAnimation("IdleSmall", "myTexture.png", seconds(1.5f), true);
	idleAnimationSmall.AddFrames(Vector2i(64, 0), spriteSize, 3);
	idleAnimationSmall.AddFrames(Vector2i(160, 0), spriteSize, 2);

	// Idle animation with 8 frames @ 0.5 sec not looping
	auto& idleAnimationOnce = animator.CreateAnimation("IdleOnce", "myTexture.png", seconds(0.5f), false);
	idleAnimationOnce.AddFrames(Vector2i(0, 0), spriteSize, 8);

	Clock clock;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Key::Num1)
					animator.SwitchAnimation("Idle");
				else if (event.key.code == Keyboard::Key::Num2)
					animator.SwitchAnimation("IdleShort");
				else if (event.key.code == Keyboard::Key::Num3)
					animator.SwitchAnimation("IdleSmall");
				else if (event.key.code == Keyboard::Key::Num4)
					animator.SwitchAnimation("IdleOnce");
			}
		}

		// Returns the elapsed time and restarts the clock
		Time deltaTime = clock.restart();

		animator.Update(deltaTime);

		window.clear(Color::Black);
		window.draw(sprite);
		window.display();
	}
}