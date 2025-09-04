#ifndef NODE_OBJECT_HPP
#define NODE_OBJECT_HPP

#include <string>
#include <memory>

#include "Node.hpp"
#include "../GameLib2D/Action.hpp"

/*前方宣言*/
class GameObject;

/// @brief ヒエラルキー上で表示する GameObject を表すNode
class NodeObject final : public Node {
private:
	std::weak_ptr<GameObject> object;                  // 所持している GameObject 
	std::vector<std::shared_ptr<NodeObject>> children; // 子 NodeObject

	/// @brief 再帰的に子 NodeObject を削除
	/// @param nodeObject 親 NodeObject の参照先
	void remove_recursively(const std::shared_ptr<NodeObject>& nodeObject);
public:
	Action<> onDestroy;                 // NodeObject を破棄した際の処理
	Action<> onAddChild;                // 子 NodeObject を追加した際の処理
	Action<const std::string&> onClick; // クリック処理

	/// @brief コンストラクタ
	/// @param obj  GameObject の参照先
	[[nodiscard]] NodeObject(const std::shared_ptr<GameObject>& obj);

	/// @brief デフォルトデストラクタ
	virtual ~NodeObject() noexcept = default;

	/// @brief 描画処理
	virtual void Draw() override;

	/// @brief 子 NodeObject を追加。
	/// @param nodeObject 参照先
	void AddChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief 子 NodeObject を除外
	/// @param nodeObject 参照先
	void RemoveChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief 子 NodeObject を返します
	/// @return 子 NodeObject
	[[nodiscard]] const std::vector<std::shared_ptr<NodeObject>>& GetChildren() const {
		return children;
	}

	/// @brief 参照している GameObject を返します。
	/// @return 参照している GameObject
	[[nodiscard]] const std::weak_ptr<GameObject>& GetGameObject() const {
		return object;
	}

	/// @brief NodeObject を生成する
	/// @param obj GameObject の参照先
	/// @return NodeObject のインスタンス
	[[nodiscard]] static const std::shared_ptr<NodeObject> Create(const std::shared_ptr<GameObject>& obj) {
		return std::make_shared<NodeObject>(obj);
	}
};

#endif 
