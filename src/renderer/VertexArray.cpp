#include "VertexArray.h"
#include "VertexBuffer.h"

namespace renderer
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &id);
		vertCount = 6;

		if (!id)
		{
			throw std::exception();
		}

		dirty = true;
		buffers.resize(20);
	}

	void VertexArray::setBuffer(int location, std::shared_ptr<VertexBuffer> buffer)
	{
		buffers.at(location) = buffer;
		dirty = true;
	}

	int VertexArray::getVertCount()
	{
		return vertCount;
	}

	GLuint VertexArray::getId()
	{
		if (dirty)
		{
			glBindVertexArray(id);

			for (size_t i = 0; i < buffers.size(); i++)
			{
				if (!buffers.at(i))
					continue;

				glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->getId());

				glVertexAttribPointer(i, buffers.at(i)->getComponents(), GL_FLOAT, GL_FALSE,
					0, (void*)0);

				glEnableVertexAttribArray(i);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}

			glBindVertexArray(0);
			dirty = false;
		}

		return id;
	}
}