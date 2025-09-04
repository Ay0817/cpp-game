#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/// @brief Hierarchy ��ŕ\������� Node �̊��N���X�B
class Node {
protected:
	std::string name;
public:
	/// @brief �R���X�g���N�^
	[[nodiscard]] Node() noexcept = default;

	/// @brief �R���X�g���N�^
	[[nodiscard]] Node(const std::string& name);

	/// @brief �f�X�g���N�^
	virtual ~Node() noexcept = default;

	/// @brief �`�揈��
	virtual void Draw() = 0;

	/// @brief Node �����擾
	/// @return Node ��
	[[nodiscard]] const std::string& GetName() const {
		return name;
	}
};

#endif 
