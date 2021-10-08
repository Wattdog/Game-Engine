#include <memory>
#include <vector>

namespace myengine
{
	struct Entity;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

	private:
		int dummy;
		std::vector<std::shared_ptr<Entity> > entities;
	};
}