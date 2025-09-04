#ifndef COMPONENT_INL
#define COMPONENT_INL

#include "GameObject.hpp"

// @brief コンポーネントを追加
template <Concept::is_component T>
std::shared_ptr<T> Component::AddComponent() {
	if (auto obj = gameObject.lock()) {
		return obj->AddComponent<T>();
	}
	else {
		Logger::LogError("ゲームオブジェクトの取得に失敗しました。");
		return nullptr;
	}

	// TODO:動的に追加された場合はここで Awake 呼び出し?
}

// @brief コンポーネントを取得
template <Concept::is_component T>
NODISCARD std::shared_ptr<T> Component::GetComponent() const {
	if (auto obj = gameObject.lock()) {
		return obj->GetComponent<T>();
	}
	else {
		Logger::LogError("ゲームオブジェクトの取得に失敗しました。");
		return nullptr;
	}
}

// @brief コンポーネントを取得
template <Concept::is_component T>
NODISCARD const std::vector<std::shared_ptr<T>> Component::GetComponents() const {
	if (auto obj = gameObject.lock()) {
		return obj->GetComponents<T>();
	}
	else {
		Logger::LogError("ゲームオブジェクトの取得に失敗しました。");
		return {};
	}
}

#endif
