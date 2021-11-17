#include "Component.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	struct Transform : Component
	{
		public:
			Transform();
			glm::mat4 getModel();
			void setPosition(glm::vec3 pos);
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
	};
}