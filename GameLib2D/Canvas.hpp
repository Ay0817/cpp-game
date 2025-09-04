#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Component.hpp"

/*�O���錾*/
class UI;

/// @brief 
class Canvas final : public Component {
private:

public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Canvas(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Canvas() noexcept = default;

	/// @brief �`�揈��
	void Render() const;
};

#endif 
