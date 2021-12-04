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
		vao = std::make_shared<renderer::VertexArray>();

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(glm::vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, 0.5f));

		vbo->add(glm::vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, 0.5f));

		vbo->add(glm::vec3(0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));

		vbo->add(glm::vec3(0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, -0.5f, -0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));

		vbo->add(glm::vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, -0.5f, 0.5f));

		vbo->add(glm::vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(glm::vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, -0.5f, -0.5f));

		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(0.5f, -0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, 0.5f, -0.5f));

		vbo->add(glm::vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(0.5f, -0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, -0.5f, -0.5f));

		vbo->add(glm::vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));

		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));
		vbo->add(glm::vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, 0.5f));

		vao->setBuffer(0, vbo);

		normalsVbo = std::make_shared<renderer::VertexBuffer>();
		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));

		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, 1.0f));

		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));

		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));

		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));

		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(-1.0f, 0.0f, 0.0f));

		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));

		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(glm::vec3(0.0f, 0.0f, -1.0f));

		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));

		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(glm::vec3(0.0f, 1.0f, 0.0f));
		
		vao->setBuffer(1, normalsVbo);
		
		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/cube_vertShader.txt", "../Assets/Shaders/cube_fragShader.txt");

		getTransform()->setPosition(glm::vec3(2.5f, 0.0f, -10.0f));
		getTransform()->setScale(glm::vec3(0.5f, 0.5f, 0.5f));

		shaderProgram->setUniform("worldSpaceLightPos", glm::vec4(1, 0.0, 1, 1));
	}

	void Cube::onDisplay()
	{
		//shaderProgram->setUniform("lightColour", glm::vec3(1, 0, 0));
		shaderProgram->setUniform("modelMat", getTransform()->getModel());

		glEnable(GL_CULL_FACE);
		
		shaderProgram->draw(vao);

		glDisable(GL_CULL_FACE);
	}

	void Cube::onTick()
	{
		getTransform()->rotate(glm::vec3(0.0f, 1.0f, 0.0f) * 45.0f * getEnvironment()->getDeltaTime());
	}
}