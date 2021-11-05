#include "SDL.h"
#include <vector>

namespace myengine
{
	struct Keyboard
	{
		public:
			bool isKeyDown(int keyCode);
			bool isKeyUp(int keyCode);
			void removeKey(SDL_Keycode key);
			std::vector<int> keys;
		private:
			
	};
}