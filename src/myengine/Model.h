#include "Component.h"

#include <renderer/renderer.h>
#include <iostream>
#include <GL/glew.h>

namespace myengine
{
	struct Model : Component
	{
		public:
			~Model();
			void onInit();
		private:
			void onDisplay();
			void onTick();
			std::shared_ptr<renderer::ShaderProgram> shaderProgram;
			std::shared_ptr<renderer::VertexBuffer> vbo;
			std::shared_ptr<renderer::VertexArray> vao;
			std::shared_ptr<renderer::Texture> textureTeaPot;
	};
}