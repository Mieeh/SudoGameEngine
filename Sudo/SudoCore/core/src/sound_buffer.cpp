#include"../include/sound/sound_buffer.h"

#include"../include/debug.h"

#include<al.h>
#include<alc.h>

namespace sudo { namespace sound { 

	SoundBuffer::SoundBuffer()
	{
		alGenBuffers(1, &buffer);
	}

	SoundBuffer::~SoundBuffer()
	{
		alDeleteBuffers(1, &buffer);
	}

	void SoundBuffer::setData(int a_format, char* a_data, int a_size, int a_sampleRate)
	{
		alBufferData(buffer, a_format, a_data, a_size, a_sampleRate);

		if (alGetError() != AL_NO_ERROR) {
			DEBUG::getInstance()->printMessage("Error generating sound buffer inside sound_buffer.cpp", LogType::Error);
			alDeleteBuffers(1, &buffer);
			return;
		}
	}
} } 