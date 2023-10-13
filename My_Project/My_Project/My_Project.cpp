#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <D:\Документы\Computer_Graphics\My_Project\lib\mathematics.hpp>
using std::ostream;  using std::istream;  using std::endl;
using std::domain_error;


using namespace std;

int main() {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8; 
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	sf::Window window(sf::VideoMode(800, 600, 32), "First Window",
		sf::Style::Titlebar | sf::Style::Close);

	glewExperimental = GL_TRUE; 

	if (GLEW_OK != glewInit()) {
		cout << "Error:: glew not init =(" << endl;
		return -1;
	}

	bool isGo = true;

	while (isGo) {
		sf::Event windowEvent;

		while (window.pollEvent(windowEvent)) { 
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				isGo = false;
				break;
			default:
				break;
			}
		}

		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);

		static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,
	 0.0f,  1.0f, 0.0f,
		};

		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		//glUseProgram(programID); //установить шейдерную программу

		glBindVertexArray(VertexArrayID); // связываем нужный VAO по id

		glEnableVertexAttribArray(0); // выбираем вершины
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); // устанавливаем нужный буфер
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized or not
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
		glBindVertexArray(0); // сбрасываем VAO
		glDisableVertexAttribArray(0); // сбрасываем array
		glUseProgram(0); //сбрасываем программу

		window.display();
	}


	window.close();
	return 0;
}