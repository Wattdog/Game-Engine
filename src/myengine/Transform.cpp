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
		/// Returns the model identity matrix

		glm::mat4 model(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));

		return model;
	}

	void Transform::setPosition(glm::vec3 pos)
	{
		/// Sets the position for the model/triangle

		position = pos;
	}

	void Transform::move(float amount)
	{
		/// Moves the position of the model/triangle using a float value

		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(0,0,1,1));
		position += fwd * amount;
	}

	void Transform::move(glm::vec3 amount)
	{
		/// Moves the position of the model/triangle using a glm::vec3 value

		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(amount, 1));
		position += fwd;
	}

	void Transform::rotate(float angle)
	{
		/// Sets the rotation for the model/triangle using a float value

		rotation.y += angle;
	}

	void Transform::rotate(glm::vec3 angle)
	{
		/// Sets the rotation for the model/triangle using a glm::vec3 value

		rotation += angle;
	}
}