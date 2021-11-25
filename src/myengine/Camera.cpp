#include "Camera.h"

namespace myengine
{
	Camera::Camera()
	{
		camPos = glm::vec3(0, 0, 0);
	}

	glm::mat4 Camera::getView()
	{
		glm::mat4 view(1.0f);
		view = glm::translate(view, camPos);

		return view;
	}

	void Camera::setCamPosition(glm::vec3 pos)
	{
		camPos = pos;
	}
}