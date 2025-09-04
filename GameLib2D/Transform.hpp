#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Component.hpp"
#include "Vector2.hpp"

// @brief �ʒu�A�X�P�[���A�p�x�A�K�w�̊Ǘ�
class Transform final : public Component {
private:
	Vector2 position;
	float scale;
	float angle;

	std::weak_ptr<Transform> parent;
	std::vector<std::shared_ptr<Transform>> children;
public:
	// @brief �f�t�H���g�R���X�g���N�^
	NODISCARD_CPP20 Transform() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Transform(std::weak_ptr<GameObject> owner);

	// @brief �e�� Transform ���Z�b�g����
	void SetParent(std::weak_ptr<Transform> newParent) {
		parent = newParent;
	}

	// @brief �q�� Transfrom��ǉ�����
	void AddChild(const std::shared_ptr<Transform>& child) {
		children.emplace_back(child);
	}

	// @brief �e�� Transform ��Ԃ�
	NODISCARD std::weak_ptr<Transform> GetParent() const {
		return parent;
	}

	// @brief �q�� Transform ��Ԃ�
	NODISCARD const std::vector<std::shared_ptr<Transform>>& GetChildren() const {
		return children;
	}
	
	// @brief �q�����O����
	void RemoveChild(const std::shared_ptr<Transform>& child) {
		std::erase(children, child);
	}

	// @brief ���W���Z�b�g����
	void SetPosition(Vector2 newPosition) {
		position = newPosition;
	}

	// @brief ���W��Ԃ�
	NODISCARD Vector2 GetPosition() const {
		return position;
	}

	// @brief �X�P�[�����Z�b�g����
	void SetScale(float newScale) {
		scale = newScale;
	}

	// @brief �X�P�[����Ԃ�
	NODISCARD float GetScale() const {
		return scale;
	}

	// @brief �p�x���Z�b�g����
	void SetAngle(float newAngle) {
		angle = newAngle;
	}

	// @brief �p�x��Ԃ�
	NODISCARD float GetAngle() const {
		return angle;
	}
};

#endif 
