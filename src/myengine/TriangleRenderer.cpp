#include "TriangleRenderer.h"

namespace myengine
{
	TriangleRenderer::~TriangleRenderer()
	{

	}

	void TriangleRenderer::onInit()
	{
		std::cout << "Initializing..." << std::endl;
	}

	void TriangleRenderer::onDisplay()
	{
		std::cout << "Displaying..." << std::endl;

		/*glUseProgram(programId);
		glBindVertexArray(vaoId);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);*/
	}
}