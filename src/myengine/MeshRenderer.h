#include "Component.h"
#include "renderer/renderer.h"

#include <memory>

namespace myengine
{
	struct Model;
	struct Texture;
	struct Shader;

	struct MeshRenderer : Component
	{
		public:
			void setMesh(std::shared_ptr<Model> model);
			void setTexture(std::shared_ptr<renderer::Texture> texture);
			void setShader(std::shared_ptr<Shader> shaderProgram);
		private:
			void onDisplay();
			std::shared_ptr<Model> mesh;
			std::shared_ptr<renderer::Texture> tex;
			std::shared_ptr<Shader> program;
	};
}