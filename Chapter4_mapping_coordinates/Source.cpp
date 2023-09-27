#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(
		VideoMode::getDesktopMode().width,
		VideoMode::getDesktopMode().height),
		"Animation");
	//AssetManager manager;

	auto wSize = window.getSize();
	View view(FloatRect(0, 0, wSize.x, wSize.y));

	window.setView(view);

	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::MouseButtonPressed)
			{
				Vector2f sceneCoords = window.mapPixelToCoords(
					Vector2i(ev.mouseButton.x, ev.mouseButton.y));
			}
		}
	}
}