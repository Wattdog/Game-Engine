#include <memory>
#include <vector>

namespace myengine
{
	struct Component;

	struct Entity
	{
		public:
			std::shared_ptr<Component> addComponent();
		private:
			std::vector<std::shared_ptr<Component>> components;
	};
}