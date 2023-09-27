#include <SFML/Graphics.hpp>
#include "AssetManager.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Pixelation");
	AssetManager manager;

	if (!Shader::isAvailable())
		return -1;

	RenderTexture rTexture;
	auto wSize = window.getSize();
	rTexture.create(wSize.x, wSize.y);

	// The sprite used for post-processing the texture
	Sprite ppSprite(rTexture.getTexture());

	// The shader used for post-processing the texture
	auto shader = AssetManager::GetShader("vertShader.vert", "pixelationShader.frag");

	shader->setUniform("uTexture", rTexture.getTexture());
	shader->setUniform("uTextureSize", static_cast<Vector2f>(rTexture.getSize()));
	shader->setUniform("uPixelSize", 4.f);

	Sprite sprite(AssetManager::GetTexture("dice.png"));
	Sprite sprite2(AssetManager::GetTexture("leaf.png"));
	sprite2.move(Vector2f(200, 100));

	while (window.isOpen())
	{
		// Handle events
		Event ev;
		while (window.pollEvent(ev)) {}

		// Update frame here

		// Render frame
		rTexture.clear();
		{
			// Draw scene here
			rTexture.draw(sprite);
			rTexture.draw(sprite2);
		}
		rTexture.display();

		window.clear();
		{
			// Post processing by applying the shader to the RenderTexture
			window.draw(ppSprite, shader);
		}
		window.display();
	}
}