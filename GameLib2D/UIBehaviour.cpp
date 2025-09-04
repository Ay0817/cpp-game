#include "UIBehaviour.hpp"
#include "GameObject.hpp"


UIBehaviour::UIBehaviour(std::weak_ptr<GameObject> owner) 
	: Behaviour(owner) {
}

bool UIBehaviour::IsActiveAndEnabled() const {
	auto obj = gameObject.lock();

	if (!obj) {
		return false;
	}

	return obj->GetActive() && GetEnable();
}

