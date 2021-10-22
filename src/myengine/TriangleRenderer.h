#include <iostream>
#include <GL/glew.h>

namespace myengine
{
	struct TriangleRenderer
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