#include "PBR_Model.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Camera.h"
#include "Math.h"

namespace myengine
{
	PBR_Model::~PBR_Model()
	{

	}

	void PBR_Model::onInit()
	{
		/**
		*	Sets up the vao, the vbo, the texture
		*   and the shader program required for the model
		*/

		std::cout << "Initializing..." << std::endl;

		// Adds the texture coordinates to the vbo
		vbo = std::make_shared<renderer::VertexBuffer>();

		// Makes the vao a shared pointer

		//vao = std::make_shared<renderer::VertexArray>("../Assets/Models/teapot/teapot3.obj");
		vao = std::make_shared<renderer::VertexArray>("../Assets/Models/monkey/monkey.obj");
		//vao = std::make_shared<renderer::VertexArray>("../Assets/Models/Sphere/Sphere.obj");
		//vao = std::make_shared<renderer::VertexArray>("../Assets/Models/curuthers/curuthers.obj");

		// Gets vao id
		vao->getId();

		// Makes the shader program a shared pointer
		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/pbrVertShader_LearnOpenGL.txt", "../Assets/Shaders/pbrFragShader_LearnOpenGL.txt");
		//shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/pbrVertShader_CodingLabs.txt", "../Assets/Shaders/pbrFragShader_CodingLabs.txt");

		// Sets the position for the model

		//getTransform()->setPosition(glm::vec3(0, 0, -2.5f));
		getTransform()->setPosition(vec3(0, 0, -10.0f));
		//getCamera()->setCamPosition(glm::vec3(0, 0, -3.5f));

		std::cout << "Displaying..." << std::endl;
	}

	void PBR_Model::onDisplay()
	{
		// Light Positions used for PBR 
		vec3 lightPositions[] =
		{
			vec3(-10.0f, 10.0f, 10.0f),
			vec3(10.0f, 10.0f, 10.0f),
			vec3(-10.0f, -10.0f, 10.0f),
			vec3(10.0f, -10.0f, 10.0f)
		};

		// Light Colors used for PBR
		vec3 lightColors[] =
		{
			vec3(10, 10, 10),
			vec3(10, 10, 10),
			vec3(10, 10, 10),
			vec3(10, 10, 10)
		};


		// Sets uniform for light positions
		for (int i = 0; i < sizeof(lightPositions) / sizeof(lightPositions[0]); i++)
		{
			shaderProgram->setUniform("lightPositions", lightPositions[i]);
		}

		// Sets uniform for light colors
		for (int i = 0; i < sizeof(lightColors) / sizeof(lightColors[0]); i++)
		{
			shaderProgram->setUniform("lightColors", lightColors[i]);
		}

		// Sets uniform for albedo, metallic, roughness and ao value
		shaderProgram->setUniform("albedo", vec3(0, 0.5, 0));
		shaderProgram->setUniform("metallic", 0.0f);
		shaderProgram->setUniform("roughness", 0.1f);
		shaderProgram->setUniform("ao", 1.0f);

		// Sets uniform for camera position
		shaderProgram->setUniform("camPos", vec3(10, 10, 0));

		// Sets uniform for model matrix
		shaderProgram->setUniform("u_Model", getTransform()->getModel());
		//shaderProgram->setUniform("u_View", getCamera()->getView());

		// Draws model
		shaderProgram->draw(vao);
	}

	void PBR_Model::onTick()
	{
		bool toogleShaderOn = false;

		/*
		Checks what key has been pressed and
		will then move/rotate the model
		*/
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

		if (getKeyboard()->isKeyDown(SDLK_q))
		{
			getTransform()->rotate(vec3(0.0f, -1.0f, 0.0f) * 45.0f * getEnvironment()->getDeltaTime());
		}

		if (getKeyboard()->isKeyDown(SDLK_e))
		{
			getTransform()->rotate(vec3(0.0f, 1.0f, 0.0f) * 45.0f * getEnvironment()->getDeltaTime());
		}
	}

}