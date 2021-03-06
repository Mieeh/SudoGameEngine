#pragma once

#include<iostream>
#include"../sudo_behaviour.h"

namespace sudo { namespace ecs {

	typedef enum {
		ACTIVE,
		DISABLED,
	} ComponentState;

	class Entity;

	class Component : public SudoBehaviour
	{
	public:
		/* Virtual Destructor */
		virtual ~Component() {
			//std::cout << "Component Removed" << std::endl;
		}

		/* Gets called at start */
		virtual void Awake() { } 

		/* Sets the component state */
		void SetComponentState(ComponentState a_newState) { m_componentState = a_newState; }

		/* Returns the state of the component */
		const ComponentState GetComponentState() { return m_componentState; }

		/* Sets the entity holder */
		void SetEntityHolder(Entity *a_newHolder) { m_entityHolder = a_newHolder; }

		/* Gets entity holder */
		Entity* GetEntityHolder() { return m_entityHolder; }

	protected:
		ComponentState m_componentState = ComponentState::ACTIVE; // Active by default
		Entity *m_entityHolder; // Pointer to the holder of this component
	};

} }