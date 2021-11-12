#include <memory>
#include <vector>
#include <SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

namespace myengine
{
	struct Entity;
	struct Screen;
	struct Environment;
	struct Keyboard;
	struct Transform;
	struct Sound;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Environment> getEnvironment();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Transform> getTransform();
		void start();
		void stop();
	private:
		bool running;
		std::vector<std::shared_ptr<Entity> > entities;
		std::shared_ptr<Environment> environment;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Transform> transform;
		std::shared_ptr<Sound> sound;
		std::weak_ptr<Core> self;
		SDL_Window* window;
		ALCdevice* device;
		ALCcontext* context;
	};
}