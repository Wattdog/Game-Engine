#include "Component.h"

#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : Component
	{
		public:
			glm::mat4 getModel();
			void setPosition(glm::vec3 pos);
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
	};
}