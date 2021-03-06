#pragma once

#include"component.h"
#include"../graphics/renderable2d.h"

namespace sudo {
	namespace math {
		class Vector3;
	}
}

namespace sudo { namespace ecs {

	class RectangleComponent : public Component, public graphics::Renderable2D {
	public:
		/* Constrcutor */
		RectangleComponent(math::Vector2 &a_size, math::Color &a_color);
		RectangleComponent();

		/* Destructor */
		~RectangleComponent();

		/* Component virtual methods */
		void Start() override;
		void Update(float deltaTime) override { }

		// Returns the 4 vertex positions of the rectangle
		std::array<math::Vector3, 4> GetPrimitivePoints() override;
	};
	
} }
