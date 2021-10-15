#include "Core.h"
#include "Entity.h"

namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		// Creates a shared pointer which will be assinged to core
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		// It will then return the shared ptr to a weak pointer 
		// which is assigned to core
		rtn->self = rtn;

		rtn->running = true;

		// It will then return the shared pointer
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();

		entity->core = self;
		entity->self = entity;

		entities.push_back(entity);

		return entity;
	}

	void Core::start()
	{
		while (running)
		{
			for (size_t ei = 0; ei < entities.size(); ++ei)
			{
				entities.at(ei)->tick();
			}
		}
	}

	void Core::stop()
	{
		running = false;
	}
}