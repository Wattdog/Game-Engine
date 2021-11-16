#include "TriangleRenderer.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"
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

		vao = std::make_shared<renderer::VertexArray>();

		vao->setBuffer(0, vbo);
		vao->getId();

		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/vertShader.txt", "../Assets/Shaders/fragShader.txt");

		getTransform()->setPosition(glm::vec3(0, 0, -2.5f));

		std::cout << "Displaying..." << std::endl;
	}

	void TriangleRenderer::onDisplay()
	{	
		shaderProgram->setUniform("u_Model", getTransform()->getModel());

		shaderProgram->draw(vao);
	}

	void TriangleRenderer::onTick()
	{
		float xPos = 0.0f;
		float yPos = 0.0f;

		if (getKeyboard()->isKeyDown(SDLK_UP))
		{
			yPos += 0.1f;
			getTransform()->setPosition(glm::vec3(xPos, yPos, -2.5f));
		}

		if (getKeyboard()->isKeyDown(SDLK_DOWN))
		{
			yPos -= 0.1f;
			getTransform()->setPosition(glm::vec3(xPos, yPos, -2.5f));
		}
		
		if (getKeyboard()->isKeyDown(SDLK_RIGHT))
		{
			xPos += 0.1f;
			getTransform()->setPosition(glm::vec3(xPos, yPos, -2.5f));
		}
		
		if (getKeyboard()->isKeyDown(SDLK_LEFT))
		{
			xPos -= 0.1f;
			getTransform()->setPosition(glm::vec3(xPos, yPos, -2.5f));
		}
	}
}