#include "Environment.h"

namespace myengine
{
	float Environment::getDeltaTime()
	{
		float idealTime = 1.0f / 80.0f;

		if (idealTime > dt)
		{
			SDL_Delay((idealTime - dt) * 1000.0f);
		}

		return dt;
	}
}