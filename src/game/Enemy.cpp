#include "Enemy.h"

void Enemy::onInitialize()
{
	getEntity()->addComponent<TriangleRenderer>();
}