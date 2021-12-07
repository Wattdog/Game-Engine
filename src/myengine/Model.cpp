#include "Model.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Camera.h"
#include "Math.h"

namespace myengine
{
	Model::~Model()
	{

	}

	void Model::onInit()
	{
		/**
		*	Sets up the vao, the vbo, the texture
		*   and the shader program required for the model
		*/

		std::cout << "Initializing..." << std::endl;

		//texture = std::make_shared<renderer::Texture>("../Assets/Textures/TeapotColourMap.bmp");
		texture = std::make_shared<renderer::Texture>("../Assets/Textures/Material.png");
		//texture = std::make_shared<renderer::Texture>("../Assets/Textures/Whiskers_diffuse.png");

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(vec2(0.0f, 0.0f));
		vbo->add(vec2(1.0f, 0.0f));
		vbo->add(vec2(1.0f, 1.0f));
		vbo->add(vec2(1.0f, 1.0f));
		vbo->add(vec2(0.0f, 1.0f));
		vbo->add(vec2(0.0f, 0.0f));
		
		//vao = std::make_shared<renderer::VertexArray>("../Assets/Models/teapot/teapot3.obj");
		vao = std::make_shared<renderer::VertexArray>("../Assets/Models/monkey/monkey.obj");
		//vao = std::make_shared<renderer::VertexArray>("../Assets/Models/curuthers/curuthers.obj");

		vao->getId();

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/vertShader.txt", "../Assets/Shaders/fragShader.txt");

		//getTransform()->setPosition(glm::vec3(0, 0, -2.5f));
		getTransform()->setPosition(vec3(0, 0, -10.0f));
		//getCamera()->setCamPosition(glm::vec3(0, 0, -3.5f));
		
		shaderProgram->setUniform("lightPos", vec3(0, 0, 0));
		shaderProgram->setUniform("lightColor", vec3(1, 0, 0));

		std::cout << "Displaying..." << std::endl;
	}

	void Model::onDisplay()
	{
		shaderProgram->setUniform("u_Texture", texture);
		
		shaderProgram->setUniform("u_Model", getTransform()->getModel());
		//shaderProgram->setUniform("u_View", getCamera()->getView());

		shaderProgram->draw(vao);
	}

	void Model::onTick()
	{
		if (getKeyboard()->isKeyDown(SDLK_UP) || getKeyboard()->isKeyDown(SDLK_w))
		{
			getTransform()->move(vec3(0, 0, -1.5f) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_DOWN) || getKeyboard()->isKeyDown(SDLK_s))
		{
			getTransform()->move(vec3(0, 0, 1.5f) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_RIGHT) || getKeyboard()->isKeyDown(SDLK_d))
		{
			getTransform()->move(vec3(1.5f, 0, 0) * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_LEFT) || getKeyboard()->isKeyDown(SDLK_a))
		{
			getTransform()->move(vec3(-1.5f, 0, 0) * getEnvironment()->getDeltaTime());
		}

		getTransform()->rotate(vec3(0.0f,1.0f,0.0f) * 45.0f * getEnvironment()->getDeltaTime());
	}

}