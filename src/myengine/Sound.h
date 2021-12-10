#include <string>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#include "Resource.h"


namespace myengine
{
	struct SoundSource;

	struct Sound : Resource
	{
		public:
			void onInitialize();
			void loadOgg(std::string fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq);
		private:
			friend struct myengine::SoundSource;
			ALuint bufferId;
			ALfloat variance;
			ALfloat vol;
	};
}