#include <myengine/myengine.h>
#include <string>

using namespace myengine;

struct Player : Component
{
	public:
		void onInit();
		void onTick();
	private:
		std::shared_ptr<MeshRenderer> mr;
		std::shared_ptr<SphereCollider> playerCol;
		std::shared_ptr<Trigger> playerTrigger;
		float yMomentum;
};