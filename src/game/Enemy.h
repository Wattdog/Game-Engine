#include <myengine/myengine.h>

using namespace myengine;

struct Enemy : Component
{
	float m_health;

	void onInitialize();
};