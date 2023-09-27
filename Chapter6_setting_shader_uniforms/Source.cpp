#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
	RenderWindow window(
		VideoMode(1280, 720),
		"AssetManager");
	AssetManager manager;

	auto shader = AssetManager::GetShader("vertShader.vert", "rippleShader.frag");
	Sprite sprite(AssetManager::GetTexture("dice.png"));

	shader->setUniform("uTexture", *sprite.getTexture());
	shader->setUniform("uPositionFreq", 0.1f);
	shader->setUniform("uSpeed", 10.f);
	shader->setUniform("uStrength", 0.02f);

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
		}

		window.clear();
		// Update the shader parameters
		shader->setUniform("uTime", clock.getElapsedTime().asSeconds());
		window.draw(sprite, shader);
		window.display();
	}
}