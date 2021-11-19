#include "Transform.h"

namespace myengine 
{
	Transform::Transform()
	{
		position = glm::vec3(0, 0, 0);
		rotation = glm::vec3(0, 0, 0);
		scale = glm::vec3(1, 1, 1);
	}

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

	void Transform::move(float amount)
	{
		glm::mat4 model(1.0f);
		model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
		model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
		model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(0,0,1,1));
		position += fwd * amount;
	}

	void Transform::move(glm::vec3 amount)
	{
		glm::mat4 model(1.0f);
		model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
		model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
		model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(amount, 1));
		position += fwd;
	}

	void Transform::rotate(float angle)
	{
		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0, 1, 0));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(0, 0 , 1, 1));
		rotation += fwd * angle;
	}
}