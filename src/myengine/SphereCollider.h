#include "Component.h"

namespace myengine
{
	struct Core;
	struct Entity;

	struct SphereCollider : Component
	{
		public:
			void onInitialize();
			void onDestroy();
			bool isColliding(std::shared_ptr<SphereCollider> _collider);
		private:
			float m_radius;
	};
}