#ifndef COMPONENT_INL
#define COMPONENT_INL

#include "GameObject.hpp"

// @brief �R���|�[�l���g��ǉ�
template <Concept::is_component T>
std::shared_ptr<T> Component::AddComponent() {
	if (auto obj = gameObject.lock()) {
		return obj->AddComponent<T>();
	}
	else {
		Logger::LogError("�Q�[���I�u�W�F�N�g�̎擾�Ɏ��s���܂����B");
		return nullptr;
	}

	// TODO:���I�ɒǉ����ꂽ�ꍇ�͂����� Awake �Ăяo��?
}

// @brief �R���|�[�l���g���擾
template <Concept::is_component T>
NODISCARD std::shared_ptr<T> Component::GetComponent() const {
	if (auto obj = gameObject.lock()) {
		return obj->GetComponent<T>();
	}
	else {
		Logger::LogError("�Q�[���I�u�W�F�N�g�̎擾�Ɏ��s���܂����B");
		return nullptr;
	}
}

// @brief �R���|�[�l���g���擾
template <Concept::is_component T>
NODISCARD const std::vector<std::shared_ptr<T>> Component::GetComponents() const {
	if (auto obj = gameObject.lock()) {
		return obj->GetComponents<T>();
	}
	else {
		Logger::LogError("�Q�[���I�u�W�F�N�g�̎擾�Ɏ��s���܂����B");
		return {};
	}
}

#endif
