#include "Component.h"
#include "Math.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	struct Transform : Component
	{
		public:
			Transform();
			mat4 getModel();
			void setPosition(vec3 pos);
			vec3 getPosition();
			void setScale(vec3 scal);
			void move(float amount);
			void move(vec3 amount);
			void rotate(float angle);
			void rotate(vec3 angle);
		private:
			vec3 position;
			vec3 rotation;
			vec3 scale;
	};
}