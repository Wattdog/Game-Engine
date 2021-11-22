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

		textureTeaPot = std::make_shared<renderer::Texture>("../Assets/Textures/Material.png");

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(glm::vec2(0.0f, 0.0f));
		vbo->add(glm::vec2(1.0f, 0.0f));
		vbo->add(glm::vec2(1.0f, 1.0f));
		vbo->add(glm::vec2(1.0f, 1.0f));
		vbo->add(glm::vec2(0.0f, 1.0f));
		vbo->add(glm::vec2(0.0f, 0.0f));
		

		vao = std::make_shared<renderer::VertexArray>("../Assets/Models/monkey/monkey.obj");

		//vao->setBuffer(0, vbo);
		vao->getId();

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/vertShader.txt", "../Assets/Shaders/fragShader.txt");

		getTransform()->setPosition(glm::vec3(0, 0, -2.5f));

		std::cout << "Displaying..." << std::endl;
	}

	void Model::onDisplay()
	{
		

		shaderProgram->setUniform("u_Texture", textureTeaPot);
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

		//getTransform()->rotate(10.0f);
	}

}