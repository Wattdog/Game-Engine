#include <myengine/myengine.h>

using namespace myengine;

struct Enemy : Component
{
	public:
		void onInit();
		void onTick();
	private:
		float xPos;
		float xStartPos;
		float yStartPos;
};