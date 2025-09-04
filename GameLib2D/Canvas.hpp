#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Component.hpp"

/*前方宣言*/
class UI;

/// @brief 
class Canvas final : public Component {
private:

public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Canvas(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Canvas() noexcept = default;

	/// @brief 描画処理
	void Render() const;
};

#endif 
