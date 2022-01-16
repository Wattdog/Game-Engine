#include <myengine/myengine.h>

using namespace myengine;

struct Enemy : Component
{
	public:
		void onInit();
		void onTick();
		void onTrigger();
		void reset();
	private:
		std::shared_ptr<Sound> sound;
		std::shared_ptr<SoundSource> source;
		float xPos;
		float xStartPos;
};