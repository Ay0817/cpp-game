#ifndef HIERARCHY_HPP
#define HIERARCHY_HPP

#include <vector>
#include <memory>
#include <string>

#include "../GameLib2D/ImGui/imgui.h"

/*�O���錾*/
class GameObject;
class NodeObject;

/// @brief Editor ��ŊK�w��\���N���X�B
class Hierarchy final {
private:
	float rate;       // �{��
	ImVec2 size;      // �T�C�Y
	std::string name; // ���ږ�

	std::vector<std::shared_ptr<NodeObject>> nodeObjects; // Hierarchy ���������Ă��� NodeObject 
	std::vector<std::shared_ptr<NodeObject>> toAdd;       // �ǉ��\�����ꂽ NodeObject
	std::vector<std::shared_ptr<NodeObject>> toDestroy;   // �j���\�����ꂽ NodeObject 

	std::shared_ptr<NodeObject> selectNode; // ���ݑI������Ă��� NodeObject

	/// @brief �ǉ��\�����s���B
	/// @param nodeObject �ǉ��Ώۂ̎Q�Ɛ�
	void request_add(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief �j���\�����s���B
	/// @param nodeObject �j���Ώۂ̎Q�Ɛ�
	void request_destroy(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief ���ݑI������Ă��� NodeObject ���ċA�I�ɒT���Z�b�g����B
	/// @param name ���ݑI������Ă��� NodeObject �� 
	/// @param nodeObject �Q�Ɛ�
	bool set_select_node_recursively(const std::string& name, const std::shared_ptr<NodeObject>& nodeObject);
public:
	/// @brief �f�X�g���N�^
	[[nodiscard]] Hierarchy();

	/// @brief �`�揈��
	void Draw() const;

	/// @brief NodeObject ��ǉ�����
	/// @param nodeObject NodeObject �̃C���X�^���X
	void Add(std::shared_ptr<NodeObject> nodeObject);

	/// @brief �q NodeObject ��ǉ�����
	/// @param nodeObject �q NodeObject �� �Q�Ɛ�
	void AddChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief NodeObject ��j������
	/// @param nodeObject �Ώۂ̎Q�Ɛ�
	void Destroy(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief NodeObject�̒ǉ����s���B
	void ProcessAdd();

	/// @brief NodeObject�̔j�����s���B
	void ProcessDestroy();

	/// @brief ���ݑI������Ă��� NodeObject ��Ԃ��܂��B
	/// @return ���ݑI������Ă��� NodeObject
	[[nodiscard]] std::shared_ptr<NodeObject> GetSelectNode() const {
		return selectNode;
	}

	/// @brief ���ݑI������Ă��� NodeObject ���Z�b�g���܂��B
	/// @param name �I������Ă��� NodeObject ��
	void SetSelectNode(const std::string& name);
};

#endif 
