#include "Component.h"

#include <GL/glew.h>
#include <renderer/renderer.h>
#include <vector>
#include <iostream>

namespace myengine
{
	struct Cube : Component
	{
		public:
			~Cube();
			void onInit();
		private:
			void onDisplay();
			void onTick();
			int numVertices;
			std::shared_ptr<renderer::VertexArray> vao;
			std::shared_ptr<renderer::VertexBuffer> vbo;
			std::shared_ptr<renderer::VertexBuffer> normalsVbo;
			std::shared_ptr<renderer::ShaderProgram> shaderProgram;
	};
}