#include "Resource.h"

#include <renderer/renderer.h>

namespace myengine
{
	struct MeshRenderer;

	struct Shader : Resource
	{
		public:
			void onInitialize();
		private:
			friend struct myengine::MeshRenderer;
			std::shared_ptr<renderer::ShaderProgram> shaderProgram;
	};
}