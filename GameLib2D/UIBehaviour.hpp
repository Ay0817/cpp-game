#ifndef UIBEHAVIOUR_HPP
#define UIBEHAVIOUR_HPP

#include "Behaviour.hpp"

class UIBehaviour : public Behaviour {
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 UIBehaviour() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 UIBehaviour(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~UIBehaviour() = default;

	// @brief GameObject �� Component ���A�N�e�B�u�ɂȂ��Ă���ꍇ�� true ��Ԃ��܂��B
	NODISCARD bool IsActiveAndEnabled() const;
};

#endif
