#include "Player.h"

void Player::onInit()
{
	std::shared_ptr<MeshRenderer> mr = getEntity()->addComponent<MeshRenderer>();
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
	if (getKeyboard()->isKeyDown(SDLK_SPACE))
	{
		yMomentum = 1.5f;
	}

	getTransform()->move(vec3(0, yMomentum, 0) * getEnvironment()->getDeltaTime());

	if (getTransform()->getPosition().y > 0.0f)
	{
		yMomentum -= getEnvironment()->getDeltaTime();
	}
}