#include "Keyboard.h"

namespace myengine
{
	bool Keyboard::isKeyDown(int keyCode)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == keyCode)
			{
				return true;
			}
		}

		return false;
	}

	bool Keyboard::isKeyUp(int keyCode)
	{
		return false;
	}

	void Keyboard::removeKey(SDL_Keycode key)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == key)
			{
				keys.erase(keys.begin() + i);
				i--;
			}
		}
	}
}