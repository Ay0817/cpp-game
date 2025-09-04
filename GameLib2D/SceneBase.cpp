#include <algorithm>

#include "SceneBase.hpp"
#include "GameObject.hpp"

SceneManagement::SceneBase::SceneBase(const Scene& scene)
	: scene(scene) {
}

void SceneManagement::SceneBase::AddObject(std::shared_ptr<GameObject>& object) {
	objects.emplace_back(std::move(object));
}

void SceneManagement::SceneBase::RemoveObject(std::shared_ptr<GameObject>& object) {
	std::erase(objects, object);
}
