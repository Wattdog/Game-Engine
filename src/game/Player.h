#include <myengine/myengine.h>
#include <string>

using namespace myengine;

struct Player : Component
{
	public:
		Player();
		void onInitialize();
	private:
		std::shared_ptr<MeshRenderer> mr;
		std::string meshPath;
		std::string shaderPath;
		vec3 position;
};