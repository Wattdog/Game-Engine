#include "Shader.h"

namespace myengine
{
	void Shader::onInitialize()
	{
		shaderProgram = std::make_shared<renderer::ShaderProgram>("../" + getPath() + ".vert",
			"../" + getPath() + ".frag");
	}
}