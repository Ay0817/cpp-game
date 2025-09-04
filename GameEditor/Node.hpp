#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/// @brief Hierarchy 上で表示される Node の基底クラス。
class Node {
protected:
	std::string name;
public:
	/// @brief コンストラクタ
	[[nodiscard]] Node() noexcept = default;

	/// @brief コンストラクタ
	[[nodiscard]] Node(const std::string& name);

	/// @brief デストラクタ
	virtual ~Node() noexcept = default;

	/// @brief 描画処理
	virtual void Draw() = 0;

	/// @brief Node 名を取得
	/// @return Node 名
	[[nodiscard]] const std::string& GetName() const {
		return name;
	}
};

#endif 
