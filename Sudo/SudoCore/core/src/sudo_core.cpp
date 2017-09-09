#include "sudo_core.h"

#include"../sudo.h"
#include"../gl_include.h"

namespace sudo{
SudoCore::SudoCore(const math::Vector2& a_windowSize, char *a_windowCaption, SudoClass *a_engineInstance)
{
	glewInit();
	glewExperimental = true;

	init(a_windowSize, a_windowCaption, a_engineInstance);
}

void SudoCore::init(const math::Vector2& a_windowSize, char* a_windowCaption, SudoClass *a_engineInstance)
{
	/* Setting the engine instance */
	m_engineInstance = a_engineInstance;

	/* Create the game window */
	m_window = new graphics::Window(a_windowSize.getX(), a_windowSize.getY(), a_windowCaption);

	/* ========================================= */
	/*               ENABLE SYSTEMS              */
	/* ========================================= */

	/* Settings system */
	m_settingsSystem = system::SettingsSystem::Instance();
	m_settingsSystem->Enable();
	m_settingsSystem->SetFPS(120);
	m_settingsSystem->SetWindowSize(a_windowSize);

	/* Input system */
	m_inputSystem = system::InputSystem::Instance();
	m_inputSystem->Enable();

	/* WorldSystem/ECS System*/
	m_worldSystem = system::WorldSystem::Instance();
	m_worldSystem->Enable();

	/* Render system */
	m_renderSystem = system::RenderSystem::Instance();
	m_renderSystem->Enable();

	/* ========================================= */

	/* User-end stuff, important we call this last after all the init stuff is done! */
	/* Call the Start method for the end-user */
	m_engineInstance->Start();

	/* Call Start on systems */
	m_worldSystem->Start();
	m_renderSystem->Start();

	/* Print the current version of the engine */
	std::cout << GetSudoVersion() << std::endl;

	/* Start the game_loop; This means Start gets called before any Update calls */
	game_loop();
}

void SudoCore::clean_up()
{
	/* This destroys  everything related to the GLFW library */
	glfwTerminate();

	/* Call CleanUp() on all systems */
	m_inputSystem->CleanUp();
	m_worldSystem->CleanUp();
	m_renderSystem->CleanUp();
	m_settingsSystem->CleanUp();

	delete m_engineInstance;
	delete m_window;
}

void SudoCore::game_loop()
{
	utility::Time::ResetTime();

	while (m_window->is_open()) 
	{
		if (utility::Time::GetElapsedTime() >= m_settingsSystem->GetFPS()/1000) {
			m_window->clear();

			/* Update the WorldSystem holding all game entities */
			m_worldSystem->Update();

			/* Call the Update method for the end-user */
			m_engineInstance->Update();

			/* Render w/OpenGL */
			m_renderSystem->Update();

			m_window->display();
			
			utility::Time::ResetTime();
		}
	}
}

}