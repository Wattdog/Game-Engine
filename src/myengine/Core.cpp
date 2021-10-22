#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Environment.h"
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		// Creates a shared pointer which will be assinged to core
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		// It will then return the shared ptr to a weak pointer 
		// which is assigned to core
		rtn->self = rtn;

		// Creates a shared pointer which will be assinged to screen
		// This will allow the shared pointer to acess functions from the
		// screen header file
		rtn->screen = std::make_shared<Screen>();

		rtn->environment = std::make_shared<Environment>();

		// This will check to see if the SDL video library has been initialized
		// If it hasn't been initialized it will then throw an exception
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		// Creates an SDL window and also get the width and height of the screen
		rtn->window = SDL_CreateWindow("My Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 400, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		// Checks to see if an OpenGL context has been created for the window
		// If it hasn't been created it will then throw an exception
		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}

		// Checks to see if glew has been initialized 
		// If it hasn't been initialized it will then throw an exception
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		glClearColor(1, 0, 0, 1);

		// Sets the running bool variable to true
		rtn->running = true;

		// It will then return the shared pointer
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		// Creates a shared pointer which will be assinged to entity
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();

		// This shared pointer is then assigned to a weak pointer
		// and the reassigned to itself
		entity->core = self;
		entity->self = entity;

		// The shared pointer is then added to the entities vector
		entities.push_back(entity);

		// It will then return the shared pointer
		return entity;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return environment;
	}

	void Core::start()
	{
		// It will first check to see if the running bool 
		// variable is true
		while (running)
		{
			// It will then run a for loop checking each entity in the
			// entities vector and then run the tick function 
			for (size_t ei = 0; ei < entities.size(); ++ei)
			{
				entities.at(ei)->tick();
			}
		}
	}

	void Core::stop()
	{
		// Sets the running bool variable to false
		running = false;
	}
}