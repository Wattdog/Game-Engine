#include "Component.h"

namespace myengine
{
	struct Core;
	struct Entity;

	struct SphereCollider : Component
	{
		public:
			void onInit();
			void onDestroy();
			bool isColliding(std::shared_ptr<SphereCollider> _collider);
			void setRadius(float rad);
		private:
			float radius;
	};
}