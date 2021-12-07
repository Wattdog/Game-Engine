#include <iostream>
#include <myengine/myengine.h>

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
   std::shared_ptr<Entity> entity2 = core->addEntity();
   std::shared_ptr<Entity> entity3 = core->addEntity();
   //std::shared_ptr<Component> component = entity->addComponent<EngineStopper>();
   //std::shared_ptr<TriangleRenderer> triangleRenderer = entity->addComponent<TriangleRenderer>();
   std::shared_ptr<Model> model = entity->addComponent<Model>();
   std::shared_ptr<Cube> cube = entity2->addComponent<Cube>();
   std::shared_ptr<Cube> cube1 = entity3->addComponent<Cube>();
   entity3->getTransform()->setPosition(vec3(-2.5f, 0.0f, -10.0f));

   std::cout << entity->getCore() << std::endl;
   //std::cout << component->getCore() << std::endl;
   //std::cout << component->getEntity() << std::endl;

   core->start();

   return 0;
}