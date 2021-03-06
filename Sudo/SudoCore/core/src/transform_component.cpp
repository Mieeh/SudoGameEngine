#include"../include/ecs/transform_component.h"

namespace sudo { namespace ecs { 

Transform::Transform()
{
	position = math::Vector3(0, 0, 0);
	scale = math::Vector3(1, 1, 1);
}

void Transform::Move(const math::Vector3 & a_vector)
{
	position = math::Vector3(position.x + a_vector.x, position.y + a_vector.y, position.z + a_vector.z);
}

void Transform::Move(const math::Vector2 & a_vector)
{
	position = math::Vector3(position.x + a_vector.x, position.y + a_vector.y, position.z);
}

void Transform::Rotate(const float a_angle)
{
	angle += a_angle;
}

void Transform::Start()
{

}

void Transform::Update(float deltaTime) 
{

}


} } 