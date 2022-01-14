#include "Score.h"
#include <iostream>

void Score::onInit()
{
	std::shared_ptr<TriangleRenderer> tr = getEntity()->addComponent<TriangleRenderer>();
	std::shared_ptr<SphereCollider> scoreCol = getEntity()->addComponent<SphereCollider>();
	scoreCol->setRadius(0.5f);
	tr->getTransform()->setPosition(vec3(0, 1, -10));
	tr->getTransform()->setScale(vec3(0.5f, 0.5f, 0.5f));
	score = 0;
}

void Score::onTrigger()
{
	score += 1;
	std::cout << "Score: " << score << std::endl;
}