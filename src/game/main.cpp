#include <iostream>
#include <myengine/myengine.h>
#include <myengine/TriangleRenderer.h>

using namespace myengine;

struct EngineStopper : Component
{
	virtual void onTick()
	{
		std::cout << "Stopping!" << std::endl;
		getCore()->stop();
	}
};

int main()
{
   std::cout << "Hello World!" << std::endl;

   std::shared_ptr<Core> core = Core::initialize();

   //std::shared_ptr<Environment> environment = 

   std::shared_ptr<Entity> entity = core->addEntity();
   //std::shared_ptr<Component> component = entity->addComponent<EngineStopper>();
   std::shared_ptr<TriangleRenderer> triangleRenderer = entity->addComponent<TriangleRenderer>();

   std::cout << entity->getCore() << std::endl;
   //std::cout << component->getCore() << std::endl;
   //std::cout << component->getEntity() << std::endl;

   core->start();

   return 0;
}