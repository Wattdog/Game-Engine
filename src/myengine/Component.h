#pragma once
#include <memory>

namespace myengine
{
	struct Core;
	struct Entity;
	struct Environment;
	struct Keyboard;

	struct Component
	{
		public:
			std::shared_ptr<Core> getCore();
			std::shared_ptr<Entity> getEntity();
			std::shared_ptr<Environment> getEnvironment();
			std::shared_ptr<Keyboard> getKeyboard();
			virtual void onTick();
			virtual void onDisplay();
			virtual void onInit();
		private:
			friend struct myengine::Entity;
			std::weak_ptr<Entity> entity;
			void tick();
			void display();
	};
}