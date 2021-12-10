#include "SoundSource.h"
#include "Sound.h"
#include <AL/al.h>

namespace myengine
{
	void SoundSource::setClip(std::shared_ptr<Sound> sound)
	{
		ALuint sid = 0;

		alGenSources(1, &sid);

		//alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, sound->bufferId);
		//alSourcef(sid, AL_PITCH, variance);
		//alSourcef(sid, AL_GAIN, vol);
		alSourcePlay(sid);
	}
}