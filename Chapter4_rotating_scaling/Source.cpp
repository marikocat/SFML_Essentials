#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <list>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Camera");
	AssetManager manager;

	auto wSize = window.getSize();

	list<View> viewList;
	// The view is centered around the world point (0, 0)
	// The view has the size of the window
	View view1(Vector2f(0, 0), Vector2f(wSize.x, wSize.y));
	// Set rotation
	view1.setRotation(45);
	// view.setSize(wSize.x * 2, wSize.y * 2);
	view1.zoom(0.5);
	view1.setViewport(FloatRect(0, 0, 0.5f, 0.5f));
	viewList.push_back(view1);

	View view2(Vector2f(0, 0), Vector2f(wSize.x, wSize.y));
	// Set rotation
	view2.setRotation(0);
	// view.setSize(wSize.x * 2, wSize.y * 2);
	view2.zoom(1);
	view2.setViewport(FloatRect(0.5f, 0, 0.5f, 0.5f));
	viewList.push_back(view2);

	View view3(Vector2f(0, 0), Vector2f(wSize.x, wSize.y));
	// Set rotation
	view3.setRotation(90);
	// view.setSize(wSize.x * 2, wSize.y * 2);
	view3.zoom(0.75);
	view3.setViewport(FloatRect(0, 0.5f, 0.5f, 0.5f));
	viewList.push_back(view3);

	View view4(Vector2f(0, 0), Vector2f(wSize.x, wSize.y));
	// Set rotation
	view4.setRotation(135);
	// view.setSize(wSize.x * 2, wSize.y * 2);
	view4.zoom(0.4);
	view4.setViewport(FloatRect(0.5f, 0.5f, 0.5f, 0.5f));
	viewList.push_back(view4);

	Vector2f spriteSize = Vector2f(32, 32);
	auto& texture = AssetManager::GetTexture("myTexture.png");

	Sprite sprite1(texture);
	sprite1.setOrigin(spriteSize * 0.5f); // Sprite origin at it's center
	sprite1.setPosition(Vector2f(-80, -80));
	//sprite1.setTextureRect(IntRect(0, 0, spriteSize.x, spriteSize.y));

	Sprite sprite2(texture);
	sprite2.setOrigin(spriteSize * 0.5f); // Sprite origin at it's center
	sprite2.setPosition(Vector2f(80, -80));
	//sprite2.setTextureRect(IntRect(32, 0, spriteSize.x, spriteSize.y));

	Sprite sprite3(texture);
	sprite3.setOrigin(spriteSize * 0.5f); // Sprite origin at it's center
	sprite3.setPosition(Vector2f(80, 80));
	//sprite3.setTextureRect(IntRect(64, 0, spriteSize.x, spriteSize.y));
	
	Sprite sprite4(texture);
	sprite4.setOrigin(spriteSize * 0.5f); // Sprite origin at it's center
	sprite4.setPosition(Vector2f(-80, 80));
	//sprite4.setTextureRect(IntRect(96, 0, spriteSize.x, spriteSize.y));

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		// Update logic
		//view.setCenter(sprite.getPosition());
		//window.setView(view);

		window.clear();
		for (auto it = viewList.begin(); it != viewList.end(); ++it)
		{
			window.setView(*it);

			window.draw(sprite1);
			window.draw(sprite2);
			window.draw(sprite3);
			window.draw(sprite4);
		}

		window.display();
	}
}