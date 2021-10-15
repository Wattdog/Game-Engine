#include <memory>
#include <vector>

namespace myengine
{
	struct Component;
	struct Core;

	struct Entity
	{
		public:
			//std::shared_ptr<Component> addComponent();

			template <typename T>
			std::shared_ptr<T> addComponent()
			{
				std::shared_ptr<T> component = std::make_shared<T>();

				component->entity = self;

				components.push_back(component);

				return component;
			}

			std::shared_ptr<Core> getCore();
		private:
			friend struct myengine::Core;
			std::vector<std::shared_ptr<Component>> components;
			std::weak_ptr<Core> core;
			std::weak_ptr<Entity> self;
			void tick();
	};
}