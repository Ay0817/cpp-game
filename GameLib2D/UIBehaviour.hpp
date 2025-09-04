#ifndef UIBEHAVIOUR_HPP
#define UIBEHAVIOUR_HPP

#include "Behaviour.hpp"

class UIBehaviour : public Behaviour {
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 UIBehaviour() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 UIBehaviour(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~UIBehaviour() = default;

	// @brief GameObject と Component がアクティブになっている場合は true を返します。
	NODISCARD bool IsActiveAndEnabled() const;
};

#endif
