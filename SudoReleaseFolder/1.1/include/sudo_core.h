#pragma once

namespace sudo {
	namespace utility {
		class Timer;
} }

namespace sudo {

	#define PRINT_FPS 0

	// Forward declarations
	namespace graphics {
		//class Window;
	}
	namespace sudo_system {
		class WindowSystem;
		class InputSystem;
		class WorldSystem;
		class SettingsSystem;
		class SoundSystem;
		class BatchRendererSystem;
		class ParticleSystem;
		class TextSystem;
	}
	namespace math {
		class Vector2;
		class Vector3;
	}
	class SudoClass;
	class CoreSettings;

	class SudoCore {
	
	public:		
		// Constructor 
		SudoCore();

		// Init, called by user
		void init(math::Vector2 a_windowSize, char* a_windowCaption, SudoClass *a_engineInstance);

		// Destructor calls clean_up 
		~SudoCore() { clean_up(); }

	private:
		// Internal methods
		void clean_up();
		void game_loop();

	private:
		SudoClass *m_engineInstance; // User-end class
		utility::Timer *timer, *deltaTimer;
		utility::Timer *realTimer;

		// All systems updated by the engine 
		sudo_system::WindowSystem		*m_windowSystem;
		sudo_system::InputSystem		*m_inputSystem;
		sudo_system::WorldSystem		*m_worldSystem;
		sudo_system::SettingsSystem		*m_settingsSystem;
		sudo_system::SoundSystem		*m_soundSystem;
		sudo_system::BatchRendererSystem *m_batchRenderer;
		sudo_system::ParticleSystem		*m_particleSystem;
		sudo_system::TextSystem			*m_textSystem;
	};

}