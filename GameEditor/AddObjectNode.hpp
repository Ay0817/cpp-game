#ifndef ADD_OBJECT_NODE_HPP
#define ADD_OBJECT_NODE_HPP

#include <memory>

#include "Node.hpp"
#include "Hierarchy.hpp"

/// @brief �I�u�W�F�N�g��ǉ����� Node
class AddObjectNode : public Node {
private:
	bool isActive; // �A�N�e�B�u���
	char buf[32];  // �I�u�W�F�N�g��

	std::shared_ptr<Hierarchy> hierarchy; // �V�[�����I�u�W�F�N�g�̊K�w���Ǘ��E�\��
public:
	/// @brief �R���X�g���N�^
	/// @param name Node ��
	[[nodiscard]] AddObjectNode(const std::string& name, const std::shared_ptr<Hierarchy>& hierarchy);

	/// @brief �`�揈��
	virtual void Draw() override;
};

#endif 
