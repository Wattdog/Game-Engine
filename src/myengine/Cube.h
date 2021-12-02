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
			GLuint vao;
			std::shared_ptr<renderer::ShaderProgram> shaderProgram;
	};
}