#include <myengine/myengine.h>

using namespace myengine;

struct Player : Component
{
	float m_health;

	void onInitialize();
};