#include "Component.h"
#include "Entity.h"
#include "Core.h"

namespace myengine
{
	std::shared_ptr<Core> Component::getCore()
	{
		// Returns the core
		return getEntity()->getCore();
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		// Returns the entity
		return entity.lock();
	}

	void Component::tick()
	{
		// Runs the onTick function
		onTick();
	}

	void Component::onTick()
	{

	}
	
}