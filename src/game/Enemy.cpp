#include "Enemy.h"

void Enemy::onInit()
{
	// Sets variables for the enemy 
	std::shared_ptr<MeshRenderer> mr = getEntity()->addComponent<MeshRenderer>();
	std::shared_ptr<SphereCollider> enemyCol = getEntity()->addComponent<SphereCollider>();
	enemyCol->setRadius(0.25f);
	mr->setMesh(getCore()->getResources()->load<Model>("Assets/Models/Sphere/Sphere"));
	mr->setShader(getCore()->getResources()->load<Shader>("Assets/Shaders/pbrShader_LearnOpenGL"));
	xStartPos = 5.5f;
	mr->getTransform()->setPosition(vec3(xStartPos, 0, -10));
	mr->getTransform()->setScale(vec3(0.25f, 0.25f, 0.25f));
	xPos = 0.0f;
	std::shared_ptr<Sound> sound = getCore()->getResources()->load<Sound>("../Assets/AudioClips/horn");
	std::shared_ptr<SoundSource> source = getEntity()->addComponent<SoundSource>();
}

void Enemy::onTick()
{
	// Takes away 0.01f every tick
	xPos -= 0.01f;

	// The enemy will then start moving towards the player
	getTransform()->move(vec3(xPos, 0, 0) * getEnvironment()->getDeltaTime());

	// If the position is less than -5.5 it will reset the enemies position
	if (getTransform()->getPosition().x < -5.5f)
	{
		reset();
	}
}

void Enemy::onTrigger()
{
	std::cout << "collider" << std::endl;
}

void Enemy::reset()
{
	// Resets enemies position and xPos
	getTransform()->setPosition(vec3(xStartPos, 0, -10));
	xPos = 0.0f;
}