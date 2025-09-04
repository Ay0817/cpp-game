#include "Component.hpp"

Component::Component(std::weak_ptr<GameObject> owner)
	: Object(""), gameObject(owner) {
}
