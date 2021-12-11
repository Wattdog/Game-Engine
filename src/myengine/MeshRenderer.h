#include "Resource.h"

#include <memory>

namespace myengine
{
	struct Model;
	struct Texture;
	struct ShaderProgram;

	struct MeshRenderer : Resource
	{
		public:
			void setMesh(std::shared_ptr<Model> model);
			void setTexture(std::shared_ptr<Texture> texture);
			void setShader(std::shared_ptr<ShaderProgram> shaderProgram);
		private:

	};
}