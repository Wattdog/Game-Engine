#include "SphereCollider.h"
#include "Core.h"
#include "Entity.h"

namespace myengine
{
	void SphereCollider::onInit()
	{
		getCore()->registerCollider(
			getEntity()->getComponent<SphereCollider>());
	}

	void SphereCollider::onDestroy()
	{
		getCore()->unregisterCollider(this);
	}

	bool SphereCollider::isColliding(std::shared_ptr<SphereCollider> _collider)
	{
		return false;
	}
}