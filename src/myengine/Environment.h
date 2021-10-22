#include <SDL.h>

namespace myengine
{
	struct Environment
	{
		public:
			float getDeltaTime();
		private:
			float dt;
	};
}