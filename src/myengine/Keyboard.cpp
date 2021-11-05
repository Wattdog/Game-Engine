#include "Keyboard.h"

namespace myengine
{
	bool Keyboard::isKeyDown(int keyCode)
	{
		return true;
	}

	bool Keyboard::isKeyUp(int keyCode)
	{
		return true;
	}

	void Keyboard::removeKey(SDL_Keycode key)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (i == key)
			{
				
			}
		}
	}
}