#include <myengine/myengine.h>

using namespace myengine;

struct Enemy : Component
{
	public:
		void onInit();
		void onTick();
		void reset();
	private:
		float xPos;
		float xStartPos;
};