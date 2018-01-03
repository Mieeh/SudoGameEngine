#include "../include/systems/settings_system.h"
#include"../include/gl_include.h"

namespace sudo { namespace sudo_system {

	SettingsSystem* SettingsSystem::_instance = nullptr;

	SettingsSystem * sudo::sudo_system::SettingsSystem::Instance()
	{
		if (_instance == nullptr)
			_instance = new SettingsSystem();
		return _instance;
	}

	const math::Vector2& SettingsSystem::GetWindowSize()
	{
		return m_windowSize;
	}

	const math::Color& SettingsSystem::GetBackgroundColor()
	{
		return m_backgroundColor;
	}

	const bool SettingsSystem::DoAutoRender()
	{
		return m_autoRender;
	}

	unsigned int SettingsSystem::GetCurrentFPS() const
	{
		return m_currentFps;
	}

	double SettingsSystem::GetCurrentMS() const
	{
		return m_currentMS;
	}

	unsigned int SettingsSystem::GetFPS() const
	{
		return m_fps;
	}

	double SettingsSystem::GetMS() const
	{
		return m_msPerFrame;
	}

	void SettingsSystem::SetWindowSize(math::Vector2& a_newWindowSize) 
	{
		m_windowSize = a_newWindowSize;

		// Audio Listener should be in the middle of the screen
		/*
		This throws unresolved external error, why the fuck does it do that!?
		SoundSystem *temp = SoundSystem::Instance();
		temp->SetListenerPosition(math::Vector3(a_newWindowSize.x / 2, a_newWindowSize.y / 2, 0));
		*/

		// This is not what I want to do 
		alListener3f(AL_POSITION, a_newWindowSize.x/2, a_newWindowSize.y/2, -1);
	}

	void SettingsSystem::SetBackgroundColor(const math::Color& a_newBackgroundColor)
	{
		m_backgroundColor = a_newBackgroundColor;
	}

	void SettingsSystem::SetBackgroundColor(const double a_newBackgroundColor)
	{
		m_backgroundColor = math::Color(a_newBackgroundColor, a_newBackgroundColor,a_newBackgroundColor, 255);
	}

	void SettingsSystem::SetWindowCaption(const char* a_newCaption)
	{
		glfwSetWindowTitle(glfwGetCurrentContext(), a_newCaption);
	}

	void SettingsSystem::SetFPS(const unsigned int a_newFPS) 
	{
		m_fps = a_newFPS;
		this->NewFpsValue();
	}

	void SettingsSystem::SetCurrentFPS(const unsigned int a_currentNewFps)
	{
		m_currentFps = a_currentNewFps;
	}

	void SettingsSystem::SetCurrentMS(const double a_newMS)
	{
		m_currentMS = a_newMS;
	}

	void SettingsSystem::NewFpsValue()
	{
		if (m_fps > 0)
			m_msPerFrame = 1000 / m_fps;
		else
			m_msPerFrame = 0;
	}

	void SettingsSystem::SetAutoRender(bool a_value) 
	{
		m_autoRender = a_value;
	}

}}