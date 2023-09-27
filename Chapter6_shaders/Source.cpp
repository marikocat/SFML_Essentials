#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	if (!Shader::isAvailable())
		return -1;

	cout << "Shaders are available\n";

	/*Shader shader;
	if (!shader.loadFromFile("vertShader.vert", "fragShader.frag"))
		return -1;*/

	string vertShader =
		"void main() {" \
		"gl_Position = gl_Vertex;" \
		"}";

	string fragShader =
		"void main() {" \
		"gl_FragColor = vec4(1, 0, 0, 1);" \
		"}";

	Shader shader;
	if (!shader.loadFromMemory(vertShader, fragShader))
		return -1;

	cout << "Shaders were loaded\n";
}