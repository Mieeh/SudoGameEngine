#pragma once

#include"../../gl_include.h"

#include"GLFW\glfw3.h"

// Forward decleration

namespace sudo {
	namespace math {
		class Vector2;
	}
}

namespace sudo { namespace system {

	class InputSystem {
	public:
		static int m_keys[1024];
		static int m_mouseKeys[24];
		//static sudo::math::Vector2 m_mousePos;
		static math::Vector2 m_mousePos;

	public:
		~InputSystem() { }
		InputSystem() { }

		static void EnableInputSystemSystem();
		static void DisableInputSystemSystem();

		/* end-user static function */
		/* Returns true if a_keycode is down */
		/* example: if(InputSystem::IsKeyPressed(GLFW_A)) { } */
		static bool IsKeyPressed(int a_keycode);

		/* end-user static function */
		/* Returns true if a_mouse_button is down */
		static bool IsMouseButtonPressed(int a_mouse_button);

		/* We might do a seperate function for GLFW_PRESS only */

		/* GLFW Callbacks */
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	};

}
}