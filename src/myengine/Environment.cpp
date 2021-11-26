#include "Environment.h"

namespace myengine
{
	Environment::Environment()
	{
		dt = 0;
		last = SDL_GetTicks();
	}

	float Environment::getDeltaTime()
	{
		/// Returns delta time

		return dt;

		/*float idealTime = 1.0f / 80.0f;

		if (idealTime > dt)
		{
			SDL_Delay((idealTime - dt) * 1000.0f);
		}

		return dt;*/
	}

	void Environment::tick()
	{
		/// Calculates current delta time

		float current = SDL_GetTicks();
		float diff = current - last;

		dt = diff / 1000.0f;

		last = current;
	}
}