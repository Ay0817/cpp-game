#ifndef GAME_EDITOR_HPP
#define GAME_EDITOR_HPP

#include <string>
#include <memory>
#include <vector>

#include "FrameRate.hpp"
#include "Hierarchy.hpp"
#include "Inspector.hpp"
#include "AddObjectNode.hpp"

/// @brief ゲーム開発用のエディタ機能を提供するクラスです。
/// @brief シーンへの干渉、オブジェクトの管理等を行えます。
class GameEditor final {
private:
	std::shared_ptr<Hierarchy> hierarchy;         // シーン内オブジェクトの階層を管理・表示
	std::unique_ptr<Inspector> inspector;         // オブジェクトが持つ値を表示・変更
	std::unique_ptr<FrameRate> frameRate;         // フレームレートを表示
	std::unique_ptr<AddObjectNode> addObjectNode; // 新しいオブジェクトノードを追加するUI
public:
	/// @brief 初期化処理
	/// @return 失敗したら false
	[[nodiscard]] bool Init();

	/// @brief 更新処理
	void Update();

	/// @brief 描画処理
	void Render() const;

	/// @brief 終了時処理
	void End();
};

#endif 
