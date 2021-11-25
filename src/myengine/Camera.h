#include "Component.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	struct Camera : Component
	{
		public:
			Camera();
			glm::mat4 getView();
			void setCamPosition(glm::vec3 pos);
		private:
			glm::vec3 camPos;
	};
}