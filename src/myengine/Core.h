#include <memory>
#include <vector>
#include <SDL.h>

namespace myengine
{
	struct Entity;
	struct Screen;
	struct Environment;
	struct Keyboard;
	struct Transform;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Environment> getEnvironment();
		std::shared_ptr<Keyboard> getKeyboard();
		void start();
		void stop();
	private:
		bool running;
		std::vector<std::shared_ptr<Entity> > entities;
		std::shared_ptr<Environment> environment;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Transform> transform;
		std::weak_ptr<Core> self;
		SDL_Window* window;
	};
}