#include <myengine/myengine.h>
#include <string>

using namespace myengine;

struct Player : Component
{
	public:
		void onInitialize();
		void onTick();
	private:
		std::shared_ptr<MeshRenderer> mr;
};