#ifndef NODE_OBJECT_HPP
#define NODE_OBJECT_HPP

#include <string>
#include <memory>

#include "Node.hpp"
#include "../GameLib2D/Action.hpp"

/*�O���錾*/
class GameObject;

/// @brief �q�G�����L�[��ŕ\������ GameObject ��\��Node
class NodeObject final : public Node {
private:
	std::weak_ptr<GameObject> object;                  // �������Ă��� GameObject 
	std::vector<std::shared_ptr<NodeObject>> children; // �q NodeObject

	/// @brief �ċA�I�Ɏq NodeObject ���폜
	/// @param nodeObject �e NodeObject �̎Q�Ɛ�
	void remove_recursively(const std::shared_ptr<NodeObject>& nodeObject);
public:
	Action<> onDestroy;                 // NodeObject ��j�������ۂ̏���
	Action<> onAddChild;                // �q NodeObject ��ǉ������ۂ̏���
	Action<const std::string&> onClick; // �N���b�N����

	/// @brief �R���X�g���N�^
	/// @param obj  GameObject �̎Q�Ɛ�
	[[nodiscard]] NodeObject(const std::shared_ptr<GameObject>& obj);

	/// @brief �f�t�H���g�f�X�g���N�^
	virtual ~NodeObject() noexcept = default;

	/// @brief �`�揈��
	virtual void Draw() override;

	/// @brief �q NodeObject ��ǉ��B
	/// @param nodeObject �Q�Ɛ�
	void AddChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief �q NodeObject �����O
	/// @param nodeObject �Q�Ɛ�
	void RemoveChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief �q NodeObject ��Ԃ��܂�
	/// @return �q NodeObject
	[[nodiscard]] const std::vector<std::shared_ptr<NodeObject>>& GetChildren() const {
		return children;
	}

	/// @brief �Q�Ƃ��Ă��� GameObject ��Ԃ��܂��B
	/// @return �Q�Ƃ��Ă��� GameObject
	[[nodiscard]] const std::weak_ptr<GameObject>& GetGameObject() const {
		return object;
	}

	/// @brief NodeObject �𐶐�����
	/// @param obj GameObject �̎Q�Ɛ�
	/// @return NodeObject �̃C���X�^���X
	[[nodiscard]] static const std::shared_ptr<NodeObject> Create(const std::shared_ptr<GameObject>& obj) {
		return std::make_shared<NodeObject>(obj);
	}
};

#endif 
