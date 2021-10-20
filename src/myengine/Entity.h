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
				// Creates a shared pointer for the component
				std::shared_ptr<T> component = std::make_shared<T>();

				// It will then assign the shared pointer to a weak pointer
				component->entity = self;

				// Adds the shared pointer to the component vector
				components.push_back(component);

				// It then returns the shared pointer 
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