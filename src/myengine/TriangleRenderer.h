#include "Component.h"

#include <renderer/renderer.h>
#include <iostream>
#include <GL/glew.h>

namespace myengine
{
	struct TriangleRenderer : Component
	{
		public:
			~TriangleRenderer();
			void onInit();
		private:
			void onDisplay();
			void onTick();
			GLuint programId;
			GLuint vboId;
			std::shared_ptr<renderer::VertexBuffer> vbo;
			GLuint vaoId;
	};
}