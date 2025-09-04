#include "Transform.hpp"

Transform::Transform(std::weak_ptr<GameObject> owner)
	: Component(owner), position(Vector2::zero()), scale(1.f), angle(0.f){
}
