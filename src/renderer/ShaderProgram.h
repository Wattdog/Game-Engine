#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <vector>
#include <iostream>
#include <memory>

namespace renderer
{
	struct VertexArray;

	struct ShaderProgram
	{
		public:
			ShaderProgram();
			~ShaderProgram();
			void draw(std::shared_ptr<VertexArray> vertexArray);
			void setUniform(glm::vec4 uniform);
			void setUniform(float uniform);
			GLuint getId();
		private:
			GLuint id;
	};
}