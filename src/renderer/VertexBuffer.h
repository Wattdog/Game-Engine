#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace renderer
{
	struct VertexBuffer
	{
		public:
			VertexBuffer();
			~VertexBuffer();
			void add(glm::vec3 value);
			void add(glm::vec4 value);
			int getComponents();
			GLuint getId();
		private:
			GLuint id;
			std::vector<float> data;
			bool dirty;
			int components;
	};
}