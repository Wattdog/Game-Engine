#include "Transform.h"

namespace myengine 
{
	glm::mat4 Transform::getModel()
	{
		return glm::mat4();
	}

	void Transform::setPosition(glm::vec3 pos)
	{
		position = pos;
	}
}