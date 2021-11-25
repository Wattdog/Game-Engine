#include "Model.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Camera.h"

namespace myengine
{
	Model::~Model()
	{

	}

	void Model::onInit()
	{
		std::cout << "Initializing..." << std::endl;

		textureTeaPot = std::make_shared<renderer::Texture>("../Assets/Textures/TeapotColourMap.bmp");

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(glm::vec2(0.0f, 0.0f));
		vbo->add(glm::vec2(1.0f, 0.0f));
		vbo->add(glm::vec2(1.0f, 1.0f));
		vbo->add(glm::vec2(1.0f, 1.0f));
		vbo->add(glm::vec2(0.0f, 1.0f));
		vbo->add(glm::vec2(0.0f, 0.0f));
		
		vao = std::make_shared<renderer::VertexArray>("../Assets/Models/teapot/teapot3.obj");

		//vao->setBuffer(0, vbo);
		vao->getId();

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/vertShader.txt", "../Assets/Shaders/fragShader.txt");

		getTransform()->setPosition(glm::vec3(0, 0, -5.0f));
		//getCamera()->setCamPosition(glm::vec3(0, 0, -3.5f));
		
		std::cout << "Displaying..." << std::endl;
	}

	void Model::onDisplay()
	{
		shaderProgram->setUniform("u_Texture", textureTeaPot);
		shaderProgram->setUniform("u_Model", getTransform()->getModel());
		//shaderProgram->setUniform("u_View", getCamera()->getView());

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

		getTransform()->rotate(glm::vec3(0,1,0) * 180.0f * getEnvironment()->getDeltaTime());
	}

}