#include <GL/glew.h>
#include <glm/glm.hpp>

namespace renderer
{
	struct Texture;

	struct Sampler
	{
		public:
			GLint id;
			Texture* texture;
	};
}