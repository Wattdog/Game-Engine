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
			GLuint programId;
			GLuint vboId;
			GLuint vaoId;
	};
}