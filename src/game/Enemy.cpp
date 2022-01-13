#include "Enemy.h"

void Enemy::onInit()
{
	getEntity()->addComponent<TriangleRenderer>();
}