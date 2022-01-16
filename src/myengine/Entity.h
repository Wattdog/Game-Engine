#include <memory>
#include <vector>

namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;
	struct SphereCollider;
	struct Trigger;

	struct Entity
	{
		public:
			//std::shared_ptr<Component> addComponent();

			template <typename T>
			std::shared_ptr<T> addComponent()
			{
				/// Adds a component to an entity

				// Creates a shared pointer for the component
				std::shared_ptr<T> component = std::make_shared<T>();

				// It will then assign the shared pointer to a weak pointer
				component->entity = self;

				// Adds the shared pointer to the component vector
				components.push_back(component);
				component->onInit();

				// It then returns the shared pointer 
				return component;
			}

			template <typename T, typename A>
			std::shared_ptr<T> addComponent(A a)
			{
				/// Adds a component to an entity and assigns a parameter to it

				// Creates a shared pointer for the component
				std::shared_ptr<T> component = std::make_shared<T>(a);

				// It will then assign the shared pointer to a weak pointer
				component->entity = self;

				// Adds the shared pointer to the component vector
				components.push_back(component);
				component->onInit();

				// It then returns the shared pointer 
				return component;
			}

			template <typename T, typename A, typename B>
			std::shared_ptr<T> addComponent(A a, B b)
			{
				/// Adds a component to an entity and assigns a parameter to it

				// Creates a shared pointer for the component
				std::shared_ptr<T> component = std::make_shared<T>(a, b);

				// It will then assign the shared pointer to a weak pointer
				component->entity = self;

				// Adds the shared pointer to the component vector
				components.push_back(component);
				component->onInit();

				// It then returns the shared pointer 
				return component;
			}

			template <typename T, typename A, typename B, typename C>
			std::shared_ptr<T> addComponent(A a, B b, C c)
			{
				/// Adds a component to an entity and assigns a parameter to it

				// Creates a shared pointer for the component
				std::shared_ptr<T> component = std::make_shared<T>(a, b, c);

				// It will then assign the shared pointer to a weak pointer
				component->entity = self;

				// Adds the shared pointer to the component vector
				components.push_back(component);
				component->onInit();

				// It then returns the shared pointer 
				return component;
			}

			template <typename T>
			std::shared_ptr<T> getComponent()
			{
				/// Returns the component 
				for (size_t ci = 0; ci < components.size(); ci++)
				{
					std::shared_ptr<T> rtn =
						std::dynamic_pointer_cast<T>(components.at(ci));

					if (rtn)
					{
						return rtn;
					}
				}
				throw std::exception("Failed to obtain specified component");
			}

			std::shared_ptr<Core> getCore();
			std::shared_ptr<Transform> getTransform();
		private:
			friend struct myengine::Core;
			friend struct myengine::Trigger;
			std::vector<std::shared_ptr<Component>> components;
			std::weak_ptr<Core> core;
			std::weak_ptr<Transform> transform;
			std::weak_ptr<Entity> self;
			void tick();
			void display();
			void colliding(std::shared_ptr<SphereCollider> collider);
	};
}