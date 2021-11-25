#include "Entity.h"
#include "Component.h"
#include "Transform.h"
#include "Camera.h"

namespace myengine
{
	std::shared_ptr<Core> Entity::getCore()
	{
		// Returns the core
		return core.lock();
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return transform.lock();
	}

	std::shared_ptr<Camera> Entity::getCamera()
	{
		return view.lock();
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