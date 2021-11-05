#include "TriangleRenderer.h"
#include <vector>

namespace myengine
{
	TriangleRenderer::~TriangleRenderer()
	{

	}

	void TriangleRenderer::onInit()
	{
		std::cout << "Initializing..." << std::endl;

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(glm::vec3(0.0f, 0.5f, 0.0f));
		vbo->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		vbo->add(glm::vec3(0.5f, -0.5f, 0.0f));

		vaoId = 0;

		glGenVertexArrays(1, &vaoId);

		if (!vaoId)
		{
			throw std::exception();
		}

		glBindVertexArray(vaoId);

		float positions[] = {
			0.0f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};

		/*vboId = 0;

		glGenBuffers(1, &vboId);

		if (!vboId)
		{
			throw std::exception();
		}

		glBindBuffer(GL_ARRAY_BUFFER, vboId);

		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);*/

		glBindBuffer(GL_ARRAY_BUFFER, vbo->getId());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
			3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		const GLchar* vertShaderSrc =
			"attribute vec3 in_Position;               " \
			"                                          " \
			"void main()                               " \
			"{                                         " \
			"   gl_Position = vec4(in_Position, 1.0);  " \
			"}                                         ";

		GLuint vertShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertShaderId, 1, &vertShaderSrc, NULL);
		glCompileShader(vertShaderId);
		GLint success = 0;
		glGetShaderiv(vertShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		const GLchar* fragShaderSrc =
			"void main()                               " \
			"{                                         " \
			"   gl_FragColor = vec4(0, 0, 1, 1);        " \
			"}                                         ";

		GLuint fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShaderId, 1, &fragShaderSrc, NULL);
		glCompileShader(fragShaderId);
		glGetShaderiv(fragShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		programId = glCreateProgram();
		glAttachShader(programId, vertShaderId);
		glAttachShader(programId, fragShaderId);

		glBindAttribLocation(programId, 0, "in_Position");

		glLinkProgram(programId);
		glGetProgramiv(programId, GL_LINK_STATUS, &success);

		if (!success)
		{
			int maxLength = 500;
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(programId, maxLength, &maxLength, &infoLog[0]);
			std::cout << &infoLog.at(0) << std::endl;;
			throw std::exception();
		}

		glDetachShader(programId, vertShaderId);
		glDeleteShader(vertShaderId);
		glDetachShader(programId, fragShaderId);
		glDeleteShader(fragShaderId);

		std::cout << "Displaying..." << std::endl;
	}

	void TriangleRenderer::onDisplay()
	{
		glUseProgram(programId);
		glBindVertexArray(vaoId);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void TriangleRenderer::onTick()
	{
		/*if (getKeyboard()->isKeyDown(SDLK_UP))
		{
			
		}*/
	}
}