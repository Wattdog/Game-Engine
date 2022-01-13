#include <iostream>
#include <myengine/myengine.h>

#include "Player.h"
#include "Enemy.h"

using namespace myengine;
using namespace renderer;

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

   std::shared_ptr<Entity> entity = core->addEntity();
   std::shared_ptr<Entity> entity_mr = core->addEntity();
   //std::shared_ptr<Entity> entity2 = core->addEntity();
   //std::shared_ptr<Entity> entity3 = core->addEntity();

   // Adds new entity along with the player component
   std::shared_ptr<Entity> pe = core->addEntity();
   std::shared_ptr<Player> pc = pe->addComponent<Player>();
   
   // Adds new entity along with the enemy component
   std::shared_ptr<Entity> ee = core->addEntity();
   std::shared_ptr<Enemy> ec = ee->addComponent<Enemy>();

   //std::shared_ptr<Sound> sound = core->getResources()->load<Sound>("../Assets/AudioClips/horn");
   //std::shared_ptr<SoundSource> source = ee->addComponent<SoundSource>();
   //source->setClip(sound);

   std::cout << entity->getCore() << std::endl;
   //std::cout << component->getCore() << std::endl;
   //std::cout << component->getEntity() << std::endl;

   core->start();

   return 0;
}