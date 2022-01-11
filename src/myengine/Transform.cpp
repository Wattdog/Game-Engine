#include "Transform.h"

namespace myengine 
{
	Transform::Transform()
	{
		position = vec3(0, 0, 0);
		rotation = vec3(0, 0, 0);
		scale = vec3(1, 1, 1);
	}

	mat4 Transform::getModel()
	{
		/// Returns the model identity matrix

		glm::mat4 model(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, radians(rotation.y), vec3(0, 1, 0));
		model = glm::rotate(model, radians(rotation.x), vec3(1, 0, 0));
		model = glm::rotate(model, radians(rotation.z), vec3(0, 0, 1));
		model = glm::scale(model, scale);

		return model;
	}

	void Transform::setPosition(vec3 pos)
	{
		/// Sets the position for the model/triangle

		position = pos;
	}

	void Transform::setScale(vec3 scal)
	{
		/// Sets the position for the model/triangle

		scale = scal;
	}

	void Transform::move(float amount)
	{
		/// Moves the position of the model/triangle using a float value

		mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * vec4(0,0,1,1));
		position += fwd * amount;
	}

	void Transform::move(glm::vec3 amount)
	{
		/// Moves the position of the model/triangle using a glm::vec3 value

		mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), vec3(0, 0, 1));
		vec3 fwd = vec3(model * glm::vec4(amount, 1));
		position += fwd;
	}

	void Transform::rotate(float angle)
	{
		/// Sets the rotation for the model/triangle using a float value

		rotation.y += angle;
	}

	void Transform::rotate(vec3 angle)
	{
		/// Sets the rotation for the model/triangle using a glm::vec3 value

		rotation += angle;
	}
}