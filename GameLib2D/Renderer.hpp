#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Component.hpp"
#include "Math.hpp"

// @brief すべてのレンダラーのための一般的な機能
class Renderer : public Component {
private:
	int order;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Renderer() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 Renderer(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Renderer() noexcept = default;

	// @brief 描画
	virtual void Render() const {}

	// @brief "OnBecameInvisible" は任意のカメラでオブジェクトが表示されなくなるときに呼び出されます。
	virtual void OnBecameInvisible() {} // TODO: OnBecameInvisible 後々追加

	// @brief "OnBecameVisible" は任意のカメラでオブジェクトが見えるようになったときに呼び出されます。
	virtual void OnBecameVisible() {} // TODO: OnBecameVisible 後々追加

	// @brief 描画順をセット(-5 ～ 5)
	void SetOrder(int newOrder) {
		order = math::Clamp(newOrder, -5, 5);
	}

	// @brief 描画順値を返す
	NODISCARD int GetOrder() const {
		return order;
	}
};

#endif 
