#include "Player.h"

void Player::onInitialize()
{
	std::shared_ptr<MeshRenderer> mr = getEntity()->addComponent<MeshRenderer>();
	mr->setMesh(getCore()->getResources()->load<Model>("Assets/Models/monkey/monkey"));
	//mr->setTexture(core->getResources()->load<Texture>("Assets/Textures/Material.png"));
	mr->setShader(getCore()->getResources()->load<Shader>("Assets/Shaders/pbrShader_LearnOpenGL"));
	mr->getTransform()->setPosition(vec3(0, 0, -10));
}

void Player::onTick()
{
	if (getKeyboard()->isKeyDown(SDLK_SPACE))
	{
		getTransform()->jump(vec3(0, 2.0f, 0) * getEnvironment()->getDeltaTime());
	}

	if (getKeyboard()->isKeyUp(SDLK_SPACE))
	{
		getTransform()->move(vec3(0, -2.0f, 0) * getEnvironment()->getDeltaTime());
	}
}