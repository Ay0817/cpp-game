#ifndef ADD_OBJECT_NODE_HPP
#define ADD_OBJECT_NODE_HPP

#include <memory>

#include "Node.hpp"
#include "Hierarchy.hpp"

/// @brief オブジェクトを追加する Node
class AddObjectNode : public Node {
private:
	bool isActive; // アクティブ状態
	char buf[32];  // オブジェクト名

	std::shared_ptr<Hierarchy> hierarchy; // シーン内オブジェクトの階層を管理・表示
public:
	/// @brief コンストラクタ
	/// @param name Node 名
	[[nodiscard]] AddObjectNode(const std::string& name, const std::shared_ptr<Hierarchy>& hierarchy);

	/// @brief 描画処理
	virtual void Draw() override;
};

#endif 
