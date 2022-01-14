#include "Player.h"

void Player::onInit()
{
	// Sets the variables for the player
	std::shared_ptr<MeshRenderer> mr = getEntity()->addComponent<MeshRenderer>();
	std::shared_ptr<SphereCollider> playerCol = getEntity()->addComponent<SphereCollider>();
	playerCol->setRadius(0.5f);
	std::shared_ptr<Trigger> playerTrigger = getEntity()->addComponent<Trigger>();
	mr->setMesh(getCore()->getResources()->load<Model>("Assets/Models/monkey/monkey"));
	//mr->setTexture(core->getResources()->load<Texture>("Assets/Textures/Material.png"));
	mr->setShader(getCore()->getResources()->load<Shader>("Assets/Shaders/pbrShader_LearnOpenGL"));
	mr->getTransform()->setPosition(vec3(0, 0, -10));
	mr->getTransform()->setScale(vec3(0.5f, 0.5f, 0.5f));
	mr->getTransform()->rotate(vec3(0, 90.0f, 0));
	yMomentum = 0.0f;
}

void Player::onTick()
{
	// If the player presses space it will set yMomentum to 1.25
	if (getKeyboard()->isKeyDown(SDLK_SPACE))
	{
		yMomentum = 1.25f;
	}

	// This will then make the player jump
	getTransform()->move(vec3(0, yMomentum, 0) * getEnvironment()->getDeltaTime());

	// If the position is greater than 0 it will start to fall
	if (getTransform()->getPosition().y > 0.0f)
	{
		yMomentum -= getEnvironment()->getDeltaTime();
	}
	// It will then reset the players position
	else
	{
		getTransform()->setPosition(vec3(0, 0, -10));
	}
}

void Player::onTrigger()
{
	std::cout << "collider" << std::endl;
}