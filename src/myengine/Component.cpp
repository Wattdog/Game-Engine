#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Environment.h"
#include "Keyboard.h"
#include "Transform.h"

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

	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return getCore()->getEnvironment();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return getCore()->getKeyboard();
	}

	std::shared_ptr<Transform> Component::getTransform()
	{
		return getCore()->getTransform();
	}

	void Component::tick()
	{
		// Runs the onTick function
		onTick();
	}

	void Component::display()
	{
		// Runs the onTick function
		onDisplay();
	}

	void Component::play()
	{
		// Runs the onTick function
		onPlay();
	}

	void Component::onTick()
	{

	}

	void Component::onDisplay()
	{
		
	}

	void Component::onPlay()
	{

	}

	void Component::onInit()
	{
		
	}
}