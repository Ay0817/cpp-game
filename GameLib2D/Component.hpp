#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <vector>

#include "Object.hpp"
#include "CppVersion.hpp"
#include "ComponentConcept.hpp"

/*--�O���錾--*/
class GameObject;

// @brief �R���|�[�l���g�̊��N���X�B
class Component : public Object {
protected:
	std::string tag;
public:
	std::weak_ptr<GameObject> gameObject;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Component() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Component(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Component() noexcept = default;

	// @brief �^�O���Z�b�g����
	void SetTag(const std::string& newTag) {
		tag = newTag;
	}

	// @brief �^�O��Ԃ�
	NODISCARD const std::string& GetTag() const {
		return tag;
	}

	// @brief �^�����Ă���^�O�ƈ�v���Ă��邩�H
	NODISCARD bool CompareTag(const std::string& other) const {
		return tag == other;
	}

	// @brief �R���|�[�l���g��ǉ�
	template <Concept::is_component T>
	std::shared_ptr<T> AddComponent();

	// @brief �R���|�[�l���g���擾
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponent() const;

	// @brief �R���|�[�l���g���擾
	template <Concept::is_component T>
	NODISCARD const std::vector<std::shared_ptr<T>> GetComponents() const;
};

#include "Component.inl"

#endif
