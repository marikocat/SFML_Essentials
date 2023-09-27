#include <SFML/Graphics.hpp>

using namespace sf;

void initShape(RectangleShape& shape, Vector2f const& pos, Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}

int main()
{
	RenderWindow window(VideoMode(480, 180), "Bad Squares");
	// Set target Frames per second
	window.setFramerateLimit(60);

	Vector2f startPos = Vector2f(50, 50);
	RectangleShape playerRect(Vector2f(50, 50));
	initShape(playerRect, startPos, Color::Green);
	RectangleShape targetRect(Vector2f(50, 50));
	initShape(targetRect, Vector2f(400, 50), Color::Blue);
	RectangleShape badRect(Vector2f(50, 100));
	initShape(badRect, Vector2f(250, 50), Color::Red);

	while (window.isOpen())
	{
		// Always moving right
		playerRect.move(1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			playerRect.move(0, 1);
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			playerRect.move(0, -1);

		// Target reached. You win. Exit game.
		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			window.close();
		// Bad square intersect. You lose. Restart.
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			playerRect.setPosition(startPos);

		window.clear(Color::Black);

		window.draw(targetRect);
		window.draw(badRect);
		window.draw(playerRect);

		window.display();
	}
}