#include <myengine/myengine.h>

using namespace myengine;

struct Score : Component
{
	public:
		void onInit();
		void onTrigger();
	private:
		std::shared_ptr<TriangleRenderer> tr;
		std::shared_ptr<SphereCollider> scoreCol;
		int score;
};