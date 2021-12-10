#include "Component.h"

#include <renderer/renderer.h>
#include <iostream>
#include <string>
#include <GL/glew.h>

namespace myengine
{
	struct PBR_Model : Component
	{
	public:
		~PBR_Model();
		void onInit();
	private:
		void onDisplay();
		void onTick();
		std::shared_ptr<renderer::ShaderProgram> shaderProgram;
		std::shared_ptr<renderer::VertexBuffer> vbo;
		std::shared_ptr<renderer::VertexArray> vao;
	};
}