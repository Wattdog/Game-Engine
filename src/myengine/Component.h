#pragma once
#include <memory>

namespace myengine
{
	struct Core;
	struct Entity;
	struct Environment;
	struct Keyboard;
	struct Transform;

	struct Component
	{
		public:
			std::shared_ptr<Core> getCore();
			std::shared_ptr<Entity> getEntity();
			std::shared_ptr<Environment> getEnvironment();
			std::shared_ptr<Keyboard> getKeyboard();
			std::shared_ptr<Transform> getTransform();
			template <typename T>
			std::shared_ptr<T> getComponent()
			{
				return getEntity()->getComponent();
			}
			virtual void onTick();
			virtual void onDisplay();
			virtual void onInit();
			virtual void onTrigger();
		private:
			friend struct myengine::Entity;
			std::weak_ptr<Entity> entity;
			
			void tick();
			void display();
			void trigger();
	};
}