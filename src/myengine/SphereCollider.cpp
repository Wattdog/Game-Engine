#include "SphereCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Math.h"
#include "Transform.h"
#include <iostream>

namespace myengine
{
	void SphereCollider::onInit()
	{
		/// Registers collider and sets radius to 1
		getCore()->registerCollider(
			getEntity()->getComponent<SphereCollider>());
		radius = 1;
	}

	void SphereCollider::onDestroy()
	{
		/// Unregisters collider
		getCore()->unregisterCollider(this);
	}

	bool SphereCollider::isColliding(std::shared_ptr<SphereCollider> _collider)
	{
		/// Gets the distance between the colliders
		float dis = distance(_collider->getTransform()->getPosition(), getTransform()->getPosition());
		/// Gets the radius for each collider
		float rad = radius + _collider->radius;

		/// Compares the distance against the radius and if the radius is less than the distance
		/// it will return true otherwise it will return false
		if (dis < rad)
		{
			std::cout << "collider" << std::endl;
			return true;
		}
		return false;
	}

	void SphereCollider::setRadius(float rad)
	{
		/// Sets the radius of an object
		radius = rad;
	}
}