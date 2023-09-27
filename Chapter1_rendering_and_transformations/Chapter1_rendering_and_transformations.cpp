#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "The title");
	window.setFramerateLimit(60); // the upper limit of the framerate

	CircleShape circleShape(50);
	circleShape.setFillColor(Color::Red);
	circleShape.setOutlineColor(Color::White);
	circleShape.setOutlineThickness(3);

	ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, Vector2f(100, 0));
	triangle.setPoint(1, Vector2f(100, 100));
	triangle.setPoint(2, Vector2f(0, 100));
	triangle.setFillColor(Color::Blue);

	RectangleShape rectShape(Vector2f(50, 50));
	rectShape.setFillColor(Color::Green);
	rectShape.setOrigin(Vector2f(25, 25));
	rectShape.setPosition(Vector2f(50, 50));
	//rectShape.setRotation(30);
	//rectShape.setScale(Vector2f(2, 1));
	//rectShape.move(Vector2f(-50, -50));

	bool moving = false;
	while (window.isOpen())
	{
		// Handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
				window.close();

			if (event.type == Event::EventType::KeyPressed &&
				event.key.code == Keyboard::Right)
				moving = true;

			if (event.type == Event::EventType::KeyReleased &&
				event.key.code == Keyboard::Right)
				moving = false;
		}

		/*if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			rectShape.rotate(1.5f);
			rectShape.move(Vector2f(1, 0));
		}*/

		// Update scene
		if (moving)
		{
			rectShape.rotate(1.5f);
			rectShape.move(Vector2f(1, 0));
		}

		

		// Render cycle
		window.clear(Color::Black);

		window.draw(circleShape);
		window.draw(rectShape);
		window.draw(triangle);

		// Render objects
		window.display();
	}

	return 0;
}