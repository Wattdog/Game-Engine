#include "Cube.h"
#include "Transform.h"
#include "Environment.h"

namespace myengine
{
	Cube::~Cube()
	{

	}

	void Cube::onInit()
	{
		vao = 0;

		glGenVertexArrays(1, &vao);

		glBindVertexArray(vao);

		float vertices[] =
		{
			-0.5f, 0.5f, 0.5f,
			-0.5f,-0.5f, 0.5f,
			 0.5f, 0.5f, 0.5f,

			-0.5f,-0.5f, 0.5f,
			 0.5f,-0.5f, 0.5f,
			 0.5f, 0.5f, 0.5f,


			 0.5f, 0.5f, 0.5f,
			 0.5f,-0.5f, 0.5f,
			 0.5f, 0.5f,-0.5f,

			 0.5f,-0.5f, 0.5f,
			 0.5f,-0.5f,-0.5f,
			 0.5f, 0.5f,-0.5f,


			-0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f,-0.5f,
			-0.5f,-0.5f, 0.5f,

			-0.5f,-0.5f, 0.5f,
			-0.5f, 0.5f,-0.5f,
			-0.5f,-0.5f,-0.5f,


			 0.5f, 0.5f,-0.5f,
			 0.5f,-0.5f,-0.5f,
			-0.5f, 0.5f,-0.5f,

			-0.5f, 0.5f,-0.5f,
			 0.5f,-0.5f,-0.5f,
			-0.5f,-0.5f,-0.5f,


			-0.5f, 0.5f,-0.5f,
			-0.5f, 0.5f, 0.5f,
			 0.5f, 0.5f,-0.5f,

			 0.5f, 0.5f,-0.5f,
			-0.5f, 0.5f, 0.5f,
			 0.5f, 0.5f, 0.5f
		};

		numVertices = 30;

		GLuint vbo = 0;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVertices * 3, vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		float normals[] =
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,

			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,

			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,

			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,

			0.0f, 0.0f,-1.0f,
			0.0f, 0.0f,-1.0f,
			0.0f, 0.0f,-1.0f,

			0.0f, 0.0f,-1.0f,
			0.0f, 0.0f,-1.0f,
			0.0f, 0.0f,-1.0f,

			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,

			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		};

		GLuint normalVbo = 0;

		glGenBuffers(1, &normalVbo);
		glBindBuffer(GL_ARRAY_BUFFER, normalVbo);

		glBufferData(GL_ARRAY_BUFFER, sizeof(float)* numVertices * 3, vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glDisableVertexAttribArray(0);

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/cube_vertShader.txt", "../Assets/Shaders/cube_fragShader.txt");

		shaderProgram->setUniform("worldSpaceLightPos", glm::vec4(1, 0.0, 1, 1));
	}

	void Cube::onDisplay()
	{
		shaderProgram->setUniform("modelMat", getTransform()->getModel());

		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, numVertices);

		glBindVertexArray(0);
	}

	void Cube::onTick()
	{
		getTransform()->rotate(glm::vec3(0.0f, 1.0f, 0.0f) * 45.0f * getEnvironment()->getDeltaTime());
	}
}