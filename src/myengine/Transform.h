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
			void move(float amount);
			void move(glm::vec3 amount);
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
	};
}