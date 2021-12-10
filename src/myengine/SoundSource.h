#include "Component.h"

namespace myengine
{
	struct Sound;

	struct SoundSource : Component
	{
		public:
			void setClip(std::shared_ptr<Sound> sound);
		private:
	};
}