#include <memory>
#include <vector>
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace myengine
{
	struct Entity;
	struct Screen;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		void start();
		void stop();
	private:
		bool running;
		std::vector<std::shared_ptr<Entity> > entities;
		std::shared_ptr<Screen> screen;
		std::weak_ptr<Core> self;
		SDL_Window* window;
	};
}