#include "Trigger.h"
#include "Core.h"
#include "Entity.h"
#include "SphereCollider.h"

namespace myengine
{
	void Trigger::onTick()
	{
		std::shared_ptr<SphereCollider> sc =
				getEntity()->getComponent<SphereCollider>();

			std::vector<std::weak_ptr<SphereCollider> >& colliders =
				getCore()->colliders;

			for (size_t ci = 0; ci < colliders.size(); ci++)
			{
				if (colliders.at(ci).lock() == sc) continue;

				if (sc->isColliding(colliders.at(ci).lock()))
				{
					getEntity()->colliding(colliders.at(ci).lock());
					colliders.at(ci).lock()->getEntity()->colliding(sc);
				}
			}
	}
}