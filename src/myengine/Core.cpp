#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Environment.h"
#include "Keyboard.h"
#include "Transform.h"
#include "Sound.h"
#include "SphereCollider.h"
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		/**
		 * \brief Sets up the entire program
		 * by intializing everything which is required
		 * to run the program
		 */

		// Creates a shared pointer which will be assinged to core
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		// It will then return the shared ptr to a weak pointer 
		//which is assigned to core 
		rtn->self = rtn;

		// brief Creates a shared pointer which will be assinged to screen.
		// This will allow the shared pointer to acess functions from the
		// screen header file
		rtn->screen = std::make_shared<Screen>();
		rtn->keyboard = std::make_shared<Keyboard>();
		rtn->environment = std::make_shared<Environment>();
		rtn->transform = std::make_shared<Transform>();
		rtn->sound = std::make_shared<Sound>();

		rtn->screen->setWidth(800);
		rtn->screen->setHeight(800);

		// This will check to see if the SDL video library has been initialized
		// If it hasn't been initialized it will then throw an exception
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		// Creates an SDL window and also get the width and height of the screen
		rtn->window = SDL_CreateWindow("My Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->screen->getWidth(), rtn->screen->getHeight(), 
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

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

		rtn->device = alcOpenDevice(NULL);

		if (!rtn->device)
		{
			throw std::exception("Failed to open audio device");
		}

		rtn->context = alcCreateContext(rtn->device, NULL);

		if (!rtn->context)
		{
			alcCloseDevice(rtn->device);
			throw std::exception("Failed to make audio current");
		}

		if (!alcMakeContextCurrent(rtn->context))
		{
			alcDestroyContext(rtn->context);
			alcCloseDevice(rtn->device);
			throw std::exception("Failed to make context current");
		}

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		ALuint id = 0;

		alGenBuffers(1, &id);

		//rtn->sound->loadOgg(path + ".ogg", bufferData, format, freq);

		//alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);

		glClearColor(0, 0, 0, 1);

		// Sets the running bool variable to true
		rtn->running = true;

		// It will then return the shared pointer
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		/**
		 * \brief Creates an entity which is then added
		 * to a vector which is used to store all of the entities
		 */

		// Creates a shared pointer which will be assinged to entity
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();

		// This shared pointer is then assigned to a weak pointer
		// and the reassigned to itself
		entity->core = self;
		entity->self = entity;
		entity->transform = entity->addComponent<Transform>();

		// The shared pointer is then added to the entities vector
		entities.push_back(entity);

		// It will then return the shared pointer
		return entity;
	}

	std::shared_ptr<Camera> Core::getCurrentCamera()
	{
		/// Returns the camera from the core

		return camera;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		/// Returns the environment from the core

		return environment;
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		/// Returns the keyboard from the core

		return keyboard;
	}

	std::shared_ptr<Transform> Core::getTransform()
	{
		/// Returns the transform from the core

		return transform;
	}

	void Core::registerCollider(std::shared_ptr<SphereCollider>())
	{
		
	}

	void Core::unregisterCollider(std::shared_ptr<SphereCollider>())
	{

	}

	void Core::start()
	{
		/**
		 * \brief Runs the main game loop.
		 * From there it will then run tick and display functions
		 * to show all of the entities created
		 */

		/// Sets a bool value to true so the game loop can run

		// It will first check to see if the running bool 
		// variable is true
		while (running)
		{
			SDL_Event incomingEvent;

			while (SDL_PollEvent(&incomingEvent))
			{
				if (incomingEvent.type == SDL_QUIT)
				{
					stop();
				}
				else if (incomingEvent.type == SDL_KEYDOWN)
				{
					keyboard->keys.push_back(incomingEvent.key.keysym.sym);
				}
				else if (incomingEvent.type == SDL_KEYUP)
				{
					keyboard->removeKey(incomingEvent.key.keysym.sym);
				}
			}

			environment->tick();

			glEnable(GL_CULL_FACE);

			glEnable(GL_DEPTH_TEST);

			// It will then run a for loop checking each entity in the
			// entities vector and then run the tick function 
			for (size_t ei = 0; ei < entities.size(); ++ei)
			{
				entities.at(ei)->tick();
			}

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			for (size_t ei = 0; ei < entities.size(); ++ei)
			{
				entities.at(ei)->display();
			}

			for (size_t ei = 0; ei < entities.size(); ++ei)
			{
				entities.at(ei)->play();
			}

			glDisable(GL_CULL_FACE);

			glDisable(GL_DEPTH_TEST);

			SDL_GL_SwapWindow(window);
		}
	}

	void Core::stop()
	{
		/// Sets a bool value to false so the game loop can will stop running

		// Sets the running bool variable to false
		running = false;
	}
}