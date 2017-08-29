#pragma once

#include"sudo_system.h"

namespace sudo { namespace system { 

	class RenderSystem : public SudoSystem {
	private:
		/* Private constructor, singleton class */
		RenderSystem() { }
		static RenderSystem *_instance;

	public:
		/* Method to get pointer to system */
		static RenderSystem *Instance();
	};

} } 