#include "Transform.h"

namespace myengine 
{
	glm::mat4 Transform::getModel()
	{
		glm::mat4 model(1.0f);
		model = glm::translate(model, position);

		return model;
	}

	void Transform::setPosition(glm::vec3 pos)
	{
		position = pos;
	}
}