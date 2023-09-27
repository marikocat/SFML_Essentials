#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	Image image;
	image.create(50, 50, Color::Red);
	Texture texture;
	texture.loadFromImage(image);

	const unsigned int kWidth = 5, kHeight = 5;

	// Array size = width * height * 4(RGBA)
	Uint8 pixels[kWidth * kHeight * 4] =
	{
		255, 255, 255, 255, // White
		0, 0, 0, 255, // Black
		255, 0, 0, 255, // Red
		128, 128, 128, 255, // Gray
		0, 255, 0, 255, // Green
		// ...all other pixels
		255, 255, 255, 255, // White
		0, 0, 0, 255, // Black
		255, 0, 0, 255, // Red
		128, 128, 128, 255, // Gray
		0, 255, 0, 255, // Green

		255, 255, 255, 255, // White
		0, 0, 0, 255, // Black
		255, 0, 0, 255, // Red
		128, 128, 128, 255, // Gray
		0, 255, 0, 255, // Green

		255, 255, 255, 255, // White
		0, 0, 0, 255, // Black
		255, 0, 0, 255, // Red
		128, 128, 128, 255, // Gray
		0, 255, 0, 255, // Green

		255, 255, 255, 255, // White
		0, 0, 0, 255, // Black
		255, 0, 0, 255, // Red
		128, 128, 128, 255, // Gray
		0, 255, 0, 255, // Green
	};

	Image image2;
	image2.create(kWidth, kHeight, pixels);
	//image2.flipHorizontally();
	image2.setPixel(2, 2, Color::Yellow);
	image2.saveToFile("image.png");

	Image image3;
	if (!image3.loadFromFile("myImage.png")) // bmp, png, tga, gif, psd, hdr, pic, and jpg (progressive JPEG is not supported)
		return -1;

	Texture texture2;
	if (!texture2.loadFromFile("myTexture.png", IntRect(0, 0, 256, 221)))
		return -1;

	RectangleShape rectShape(Vector2f(600, 600));
	rectShape.setTexture(&texture2);

	RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), 
		"texture sample", Style::Fullscreen);

	Texture texture3;
	if (!texture3.loadFromFile("mapleLeaf.png"))
		return -1;
	Vector2u textureSize = texture3.getSize();
	float rectWidth = static_cast<float>(textureSize.x);
	float rectHeight = static_cast<float>(textureSize.y);
	RectangleShape rectShape2(Vector2f(rectWidth, rectHeight));
	rectShape2.setTexture(&texture3);

	ConvexShape shape(5);
	shape.setPoint(0, Vector2f(0, 0));
	shape.setPoint(1, Vector2f(200, 0));
	shape.setPoint(2, Vector2f(180, 120));
	shape.setPoint(3, Vector2f(100, 200));
	shape.setPoint(4, Vector2f(20, 120));
	shape.setTexture(&texture3);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(Color::Red);
	shape.move(20, 20);

	Texture texture4;
	texture4.loadFromFile("dice.png", IntRect(0, 0, 128, 221));
	texture4.setRepeated(true);

	RectangleShape rectShape3(Vector2f(128 * 3, 221 * 2));
	rectShape3.setTextureRect(IntRect(0, 0, 128 * 3, 221 * 2));

	rectShape3.setTexture(&texture4);

	Texture texture5;
	texture5.loadFromFile("egg.png");
	texture5.setSmooth(true);
	RectangleShape rectShape5(Vector2f(texture5.getSize().x * 1.5, texture5.getSize().y * 1.5));
	rectShape5.setTexture(&texture5);

	Texture texture6;
	texture6.loadFromFile("egg.png");
	RectangleShape rectShape6(Vector2f(texture6.getSize().x * 1.5, texture6.getSize().y * 1.5));
	rectShape6.setTexture(&texture6);
	rectShape6.move(texture6.getSize().x * 1.5, 0);

	Sprite sp(texture3);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == Keyboard::Key::Escape)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(rectShape5);
		window.draw(rectShape6);
		window.draw(sp);
		window.display();
	}
}