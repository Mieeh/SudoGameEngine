#include "sound_component.h"

#include"../sound/sound_include.h"

#include<al.h>
#include<alc.h>

#include"entity.h"

#include"../debug.h"

namespace sudo { namespace ecs {

bool isBigEndian()
{
	int a = 1;
	return !((char*)&a)[0];
}

int convertToInt(char* buffer, int len)
{
	int a = 0;
	if (!isBigEndian())
		for (int i = 0; i<len; i++)
			((char*)&a)[i] = buffer[i];
	else
		for (int i = 0; i<len; i++)
			((char*)&a)[3 - i] = buffer[i];
	return a;
}

char* loadWAV(const char* fn, int& chan, int& samplerate, int& bps, int& size, int& format)
{
	char buffer[4];
	std::ifstream in(fn, std::ios::binary);

	// Master riff chunk at the first 4 bytes should be "RIFF" if it's a .wav file
	in.read(buffer, 4);
	if (strncmp(buffer, "RIFF", 4) != 0)
	{
		std::cout << "this is not a valid WAVE file" << std::endl;
		return NULL;
	}

	// Still master riff chunk
	in.read(buffer, 4);		// 4+n
	in.read(buffer, 4);     // WAVE

	in.read(buffer, 4);     // fmt
	in.read(buffer, 4);     // Chunk size: 16, 18 or 40
	in.read(buffer, 2);     // Format code: 1
	in.read(buffer, 2);
	chan = convertToInt(buffer, 2);

	in.read(buffer, 4);		// Sampling rate
	samplerate = convertToInt(buffer, 4);

	in.read(buffer, 4);		// Data Rate (byte/sec)
	in.read(buffer, 2);		// Data block size (bytes)
	in.read(buffer, 2);		// Bits per sample
	bps = convertToInt(buffer, 2);

	in.read(buffer, 4);     // Subchunk2ID -> "data"
	in.read(buffer, 4);		// Subchunk2Size -> NumSamples * NumChannels * BitsPerSample/8
	size = convertToInt(buffer, 4);

	char* data = new char[size];
	in.read(data, size);	// Reading the actual waveform data 

							// Setting the format
	if (chan == 1) {
		if (bps == 8)
			format = AL_FORMAT_MONO8;
		else
			format = AL_FORMAT_MONO16;
	}
	else {
		if (bps == 8)
			format = AL_FORMAT_STEREO8;
		else
			format = AL_FORMAT_STEREO16;
	}

	// Return the waveform data
	return data;
}

SoundComponent::SoundComponent(const char * a_soundPath)
{
	m_soundPath = a_soundPath;

	// Loading .wav file
	int format, size, sampleRate, channel, bps;
	char* data = loadWAV(m_soundPath, channel, sampleRate, bps, size, format);

	// Creating the sound buffer
	soundBuffer = new sound::SoundBuffer();
	soundBuffer->setData(format, data, size, sampleRate);

	// Creating the sound source
	soundSource = new sound::SoundSource(soundBuffer->getBufferId());
}

void SoundComponent::Start() 
{

}

void SoundComponent::Update() 
{
	// Update the source's position to be identical to the m_entityHolder-transform->position! 
	// Important for the dynamic sound OpenAL provides
	if (soundSource->getPosition() != m_entityHolder->transform->position) {
		//soundSource->setPosition(m_entityHolder->transform->position);
	}
}

sound::SoundSource *SoundComponent::GetSoundSource() 
{
	return soundSource;
}

} } 