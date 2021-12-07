#include "Cube.h"
#include "Transform.h"
#include "Environment.h"
#include "Math.h"

namespace myengine
{
	Cube::~Cube()
	{

	}

	void Cube::onInit()
	{
		/**
		*	Sets up the vao, the vbo, the normalVbo 
		*   and the shader program required to 
		*   create the cube
		*/

		vao = std::make_shared<renderer::VertexArray>();

		vbo = std::make_shared<renderer::VertexBuffer>();
		vbo->add(vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(vec3(0.5f, 0.5f, 0.5f));

		vbo->add(vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(vec3(0.5f, -0.5f, 0.5f));
		vbo->add(vec3(0.5f, 0.5f, 0.5f));

		vbo->add(vec3(0.5f, 0.5f, 0.5f));
		vbo->add(vec3(0.5f, -0.5f, 0.5f));
		vbo->add(vec3(0.5f, 0.5f, -0.5f));

		vbo->add(vec3(0.5f, -0.5f, 0.5f));
		vbo->add(vec3(0.5f, -0.5f, -0.5f));
		vbo->add(vec3(0.5f, 0.5f, -0.5f));

		vbo->add(vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(vec3(-0.5f, -0.5f, 0.5f));

		vbo->add(vec3(-0.5f, -0.5f, 0.5f));
		vbo->add(vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(vec3(-0.5f, -0.5f, -0.5f));

		vbo->add(vec3(0.5f, 0.5f, -0.5f));
		vbo->add(vec3(0.5f, -0.5f, -0.5f));
		vbo->add(vec3(-0.5f, 0.5f, -0.5f));

		vbo->add(vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(vec3(0.5f, -0.5f, -0.5f));
		vbo->add(vec3(-0.5f, -0.5f, -0.5f));

		vbo->add(vec3(-0.5f, 0.5f, -0.5f));
		vbo->add(vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(glm::vec3(0.5f, 0.5f, -0.5f));

		vbo->add(vec3(0.5f, 0.5f, -0.5f));
		vbo->add(vec3(-0.5f, 0.5f, 0.5f));
		vbo->add(vec3(0.5f, 0.5f, 0.5f));

		vao->setBuffer(0, vbo);

		normalsVbo = std::make_shared<renderer::VertexBuffer>();
		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));

		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, 1.0f));

		normalsVbo->add(vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(glm::vec3(1.0f, 0.0f, 0.0f));

		normalsVbo->add(vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(1.0f, 0.0f, 0.0f));

		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));

		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));
		normalsVbo->add(vec3(-1.0f, 0.0f, 0.0f));

		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));

		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));
		normalsVbo->add(vec3(0.0f, 0.0f, -1.0f));

		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));

		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));
		normalsVbo->add(vec3(0.0f, 1.0f, 0.0f));
		
		vao->setBuffer(1, normalsVbo);
		
		shaderProgram = std::make_shared<renderer::ShaderProgram>("../Assets/Shaders/cube_vertShader.txt", "../Assets/Shaders/cube_fragShader.txt");

		getTransform()->setPosition(vec3(2.5f, 0.0f, -10.0f));
		getTransform()->setScale(vec3(1.0f, 1.0f, 1.0f));

		shaderProgram->setUniform("worldSpaceLightPos", vec4(1, 10.0, 1, 1));
	}

	void Cube::onDisplay()
	{
		shaderProgram->setUniform("lightColor", vec3(1, 0, 0));
		shaderProgram->setUniform("modelMat", getTransform()->getModel());

		glEnable(GL_CULL_FACE);
		
		shaderProgram->draw(vao);

		glDisable(GL_CULL_FACE);
	}

	void Cube::onTick()
	{
		getTransform()->rotate(vec3(0.0f, 1.0f, 0.0f) * 45.0f * getEnvironment()->getDeltaTime());
	}
}