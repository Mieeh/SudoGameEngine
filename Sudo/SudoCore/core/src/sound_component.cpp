#include "../include/ecs/sound_component.h"

#include"../include/sound/sound_include.h"

#include<al.h>
#include<alc.h>

#include"../include/ecs/entity.h"

#include"../include/debug.h"

#include"../include/math/vector2.h"
#include"../include/graphics/renderable2d.h"

#include"../include/ecs/entity.h"
#include"../include/ecs/transform_component.h"

namespace sudo { namespace ecs {

SoundComponent::SoundComponent(const char* a_soundName, const char * a_soundPath)
{
	// Loading .wav file
	int format, size, sampleRate, channel, bps;
	char* data = loadWAV(a_soundPath, channel, sampleRate, bps, size, format);

	sound::SoundBuffer *buffer = new sound::SoundBuffer;
	buffer->setData(format, data, size, sampleRate);
	sound::SoundSource *source = new sound::SoundSource(buffer->getBufferId());
	
	m_soundList.insert(std::pair<const char*, SoundStruct*>(a_soundName, new SoundStruct{buffer, source} ));
}

SoundComponent::SoundComponent()
{
}

void SoundComponent::AddSound(const char * a_soundName, const char * a_soundPath)
{
	// Loading .wav file
	int format, size, sampleRate, channel, bps;
	char* data = loadWAV(a_soundPath, channel, sampleRate, bps, size, format);

	sound::SoundBuffer *buffer = new sound::SoundBuffer;
	buffer->setData(format, data, size, sampleRate);
	sound::SoundSource *source = new sound::SoundSource(buffer->getBufferId());

	m_soundList.insert(std::pair<const char*, SoundStruct*>(a_soundName, new SoundStruct{ buffer, source }));
}

void SoundComponent::Start() 
{

}

void SoundComponent::Update(float deltaTime) 
{

}

sound::SoundSource *SoundComponent::GetSoundSource(const char* a_name) 
{
	return m_soundList.at(a_name)->soundSource;
}

std::map<const char*, SoundStruct*> SoundComponent::GetSoundList()
{
	return m_soundList;
}

} } 