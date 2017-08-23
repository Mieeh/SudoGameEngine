#pragma once

namespace sudo { namespace ecs {

	class Component
	{
	public:
		/* Virtual Destructor */
		virtual ~Component() { }

		/* Activates the component */
		virtual void Activate() { m_isActive = true; }

		/* Disables the component */
		virtual void Disable() { m_isActive = false; }

		/* Updates the component behaviour */
		virtual void Update() = 0;

		/* Starts, updates the necc behvaiours at start */
		virtual void Start() = 0;

		/* Returns the name of the component */
		virtual const char* GetName() { return m_name; }
		 
	protected:
		unsigned char m_isActive; // Depending on this value update the component behaviours
		const char* m_name; // Name of the component
	};

} }