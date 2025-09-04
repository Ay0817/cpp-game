#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Component.hpp"
#include "Vector2.hpp"

// @brief 位置、スケール、角度、階層の管理
class Transform final : public Component {
private:
	Vector2 position;
	float scale;
	float angle;

	std::weak_ptr<Transform> parent;
	std::vector<std::shared_ptr<Transform>> children;
public:
	// @brief デフォルトコンストラクタ
	NODISCARD_CPP20 Transform() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 Transform(std::weak_ptr<GameObject> owner);

	// @brief 親の Transform をセットする
	void SetParent(std::weak_ptr<Transform> newParent) {
		parent = newParent;
	}

	// @brief 子の Transfromを追加する
	void AddChild(const std::shared_ptr<Transform>& child) {
		children.emplace_back(child);
	}

	// @brief 親の Transform を返す
	NODISCARD std::weak_ptr<Transform> GetParent() const {
		return parent;
	}

	// @brief 子の Transform を返す
	NODISCARD const std::vector<std::shared_ptr<Transform>>& GetChildren() const {
		return children;
	}
	
	// @brief 子を除外する
	void RemoveChild(const std::shared_ptr<Transform>& child) {
		std::erase(children, child);
	}

	// @brief 座標をセットする
	void SetPosition(Vector2 newPosition) {
		position = newPosition;
	}

	// @brief 座標を返す
	NODISCARD Vector2 GetPosition() const {
		return position;
	}

	// @brief スケールをセットする
	void SetScale(float newScale) {
		scale = newScale;
	}

	// @brief スケールを返す
	NODISCARD float GetScale() const {
		return scale;
	}

	// @brief 角度をセットする
	void SetAngle(float newAngle) {
		angle = newAngle;
	}

	// @brief 角度を返す
	NODISCARD float GetAngle() const {
		return angle;
	}
};

#endif 
