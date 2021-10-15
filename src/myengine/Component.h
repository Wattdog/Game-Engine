#include <memory>

namespace myengine
{
	struct Core;
	struct Entity;

	struct Component
	{
		public:
			std::shared_ptr<Core> getCore();
			std::shared_ptr<Entity> getEntity();
			virtual void onTick();
		private:
			friend struct myengine::Entity;
			std::weak_ptr<Entity> entity;
			void tick();
	};
}