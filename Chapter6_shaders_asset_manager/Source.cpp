#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
	RenderWindow window(
		VideoMode(1280, 720),
		"AssetManager");
	AssetManager manager;

	auto shader = AssetManager::GetShader("vertShader.vert", "fragShader.frag");
	Sprite sprite(AssetManager::GetTexture("leaf.png"));

	Time m_GameTimeTotal;
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

		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;

		window.clear();
		// Update the shader parameters
		shader->setUniform("uTime", m_GameTimeTotal.asSeconds());

		window.draw(sprite, shader);
		window.display();
	}
}