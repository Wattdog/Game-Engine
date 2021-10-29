#include "SDL.h"
#include <vector>

namespace myengine
{
	struct Keyboard
	{
		public:
			bool getKey(int keyCode);
			bool getKeyDown(int keyCode);
			bool getKeyUp(int keyCode);
		private:
			std::vector<int> keyCodes;
	};
}