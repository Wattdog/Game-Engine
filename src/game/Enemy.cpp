#include "Enemy.h"

void Enemy::onInit()
{
	std::shared_ptr<MeshRenderer> mr = getEntity()->addComponent<MeshRenderer>();
	mr->setMesh(getCore()->getResources()->load<Model>("Assets/Models/Sphere/Sphere"));
	mr->setShader(getCore()->getResources()->load<Shader>("Assets/Shaders/pbrShader_LearnOpenGL"));
	xStartPos = 0.5f;
	yStartPos = 0.0f;
	mr->getTransform()->setPosition(vec3(xStartPos, yStartPos, 0));
	mr->getTransform()->setScale(vec3(0.05f, 0.05f, 0.05f));
	xPos = 0.0f;
}

void Enemy::onTick()
{
	xPos -= 0.001f;

	getTransform()->move(vec3(xPos, 0, 0) * getEnvironment()->getDeltaTime());
}