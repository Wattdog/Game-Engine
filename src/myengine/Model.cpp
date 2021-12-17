#include "Model.h"

namespace myengine
{
	void Model::onInitialize()
	{
		vao = std::make_shared <renderer::VertexArray>("../" + getPath() + ".obj");
	}
}