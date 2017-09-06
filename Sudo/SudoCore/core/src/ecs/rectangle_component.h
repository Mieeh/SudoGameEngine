#pragma once

#include"component.h"
#include"../graphics/renderable2d.h"

namespace sudo { namespace ecs {

	// Forward decleration
	class Transform;

	class RectangleComponent : public Component, public graphics::Renderable2D {
	public:
		/* Constrcutor */
		RectangleComponent(math::Vector2 &a_size, math::Vector4 &a_color);

		/* Component class methods */
		void Start()	override;
		void Update()	override { }

		/* Renderable2D class methods */
		void bind()		override;
		void unbind()	override;

	private:
		unsigned int VBO, VAO, EBO, CBO;
	};
	
} }
