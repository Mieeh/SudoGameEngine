#pragma once

#include"math\vector2.h"
#include"math\vector3.h"
#include"utility\timer.h"

namespace sudo {

	// Forward declarations
	namespace graphics {
		class Window;
	}
	namespace system {
		class InputSystem;
		class WorldSystem;
		class RenderSystem;
		class SettingsSystem;
	}
	class SudoClass;
	class CoreSettings;
	
	
	class SudoCore {
	private:
		/* ======================================================================= */
		/* ======================> CORE ENGINE DATA <============================= */
		/* ======================================================================= */
		graphics::Window *m_window;
		SudoClass *m_engineInstance;

		/* Systems */
		system::InputSystem		*m_inputSystem;
		system::WorldSystem		*m_worldSystem;
		system::RenderSystem	*m_renderSystem;
		system::SettingsSystem	*m_settingsSystem;

		utility::Timer *timer;

		/* ======================================================================= */
		/* ======================> CORE ENGINE METHODS <========================== */
		/* ======================================================================= */
		/* init method is called from constructor */
		/* takes in all necc data to create a engine instance */
		void init(const math::Vector2& a_windowSize, char* a_windowCaption, SudoClass *a_engineInstance);

		/* Does the necc clean up */
		void clean_up();
		
		/* Runs the game loop */
		void game_loop();
	
	public:		
		/* Destructor */
		~SudoCore() { clean_up(); }

		/* Default Constructor */
		SudoCore(
			const math::Vector2& a_windowSize, 
			char *a_windowCaption,
			SudoClass *a_engineInstance
		);
	};

}