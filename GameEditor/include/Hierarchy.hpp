#ifndef HIERARCHY_HPP
#define HIERARCHY_HPP

#include <vector>
#include <memory>
#include <string>

#include "../GameLib2D/ImGui/imgui.h"

/*前方宣言*/
class GameObject;
class NodeObject;

/// @brief Editor 上で階層を表すクラス。
class Hierarchy final {
private:
	float rate;       // 倍率
	ImVec2 size;      // サイズ
	std::string name; // 項目名

	std::vector<std::shared_ptr<NodeObject>> nodeObjects; // Hierarchy が所持している NodeObject 
	std::vector<std::shared_ptr<NodeObject>> toAdd;       // 追加申請された NodeObject
	std::vector<std::shared_ptr<NodeObject>> toDestroy;   // 破棄申請された NodeObject 

	std::shared_ptr<NodeObject> selectNode; // 現在選択されている NodeObject

	/// @brief 追加申請を行う。
	/// @param nodeObject 追加対象の参照先
	void request_add(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief 破棄申請を行う。
	/// @param nodeObject 破棄対象の参照先
	void request_destroy(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief 現在選択されている NodeObject を再帰的に探しセットする。
	/// @param name 現在選択されている NodeObject 名 
	/// @param nodeObject 参照先
	bool set_select_node_recursively(const std::string& name, const std::shared_ptr<NodeObject>& nodeObject);
public:
	/// @brief デストラクタ
	[[nodiscard]] Hierarchy();

	/// @brief 描画処理
	void Draw() const;

	/// @brief NodeObject を追加する
	/// @param nodeObject NodeObject のインスタンス
	void Add(std::shared_ptr<NodeObject> nodeObject);

	/// @brief 子 NodeObject を追加する
	/// @param nodeObject 子 NodeObject の 参照先
	void AddChild(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief NodeObject を破棄する
	/// @param nodeObject 対象の参照先
	void Destroy(const std::shared_ptr<NodeObject>& nodeObject);

	/// @brief NodeObjectの追加を行う。
	void ProcessAdd();

	/// @brief NodeObjectの破棄を行う。
	void ProcessDestroy();

	/// @brief 現在選択されている NodeObject を返します。
	/// @return 現在選択されている NodeObject
	[[nodiscard]] std::shared_ptr<NodeObject> GetSelectNode() const {
		return selectNode;
	}

	/// @brief 現在選択されている NodeObject をセットします。
	/// @param name 選択されている NodeObject 名
	void SetSelectNode(const std::string& name);
};

#endif 
