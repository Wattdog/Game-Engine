#include "Enemy.h"

void Enemy::onInit()
{
	std::shared_ptr<TriangleRenderer> enemy = getEntity()->addComponent<TriangleRenderer>();
	xStartPos = 0.5f;
	yStartPos = 0.5f;
	enemy->getTransform()->setPosition(vec3(xStartPos, yStartPos, 0));
	enemy->getTransform()->setScale(vec3(0.1f, 0.1f, 0.1f));
	xPos = 0.0f;
}

void Enemy::onTick()
{
	xPos -= 0.001f;

	getTransform()->move(vec3(xPos, 0, 0) * getEnvironment()->getDeltaTime());
}