#include "Model.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"

namespace myengine
{
	Model::~Model()
	{

	}

	void Model::onInit()
	{
		std::cout << "Initializing..." << std::endl;

		vbo = std::make_shared<renderer::VertexBuffer>();

		vao = std::make_shared<renderer::VertexArray>("../Assets/Models/teapot3.obj");

		//vao->setBuffer(0, vbo);
		vao->getId();

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/vertShader.txt", "../Assets/Shaders/fragShader.txt");

		getTransform()->setPosition(glm::vec3(0, 0, -2.5f));

		std::cout << "Displaying..." << std::endl;
	}

	void Model::onDisplay()
	{
		shaderProgram->setUniform("u_Model", getTransform()->getModel());

		shaderProgram->draw(vao);
	}

	void Model::onTick()
	{
		if (getKeyboard()->isKeyDown(SDLK_UP))
		{
			getTransform()->move(glm::vec3(0, 0, -1.5f) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_DOWN))
		{
			getTransform()->move(glm::vec3(0, 0, 1.5f) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_RIGHT))
		{
			getTransform()->move(glm::vec3(1.5f, 0, 0) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_LEFT))
		{
			getTransform()->move(glm::vec3(-1.5f, 0, 0) * getEnvironment()->getDeltaTime());
		}
	}

}