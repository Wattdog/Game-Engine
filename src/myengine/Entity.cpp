#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myengine
{
	std::shared_ptr<Core> Entity::getCore()
	{
		// Returns the core
		return core.lock();
	}

	void Entity::tick()
	{
		// Runs a for loop to check each component which has 
		// been added to the entity and then runs the tick function
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->tick();
		}
	}

	void Entity::display()
	{
		// Runs a for loop to check each component which has 
		// been added to the entity and then runs the display function
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->display();
		}
	}

	void Entity::play()
	{
		// Runs a for loop to check each component which has 
		// been added to the entity and then runs the play function
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->play();
		}
	}
}