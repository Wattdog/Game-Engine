#include "Component.h"

#include <vector>
#include <memory>

namespace myengine
{
	struct Core;
	struct Entity;
	struct SphereCollider;

	struct Trigger : Component
	{
		public:
			void onTick();
	};
}