#ifndef APP_SYSTEM_HPP
#define APP_SYSTEM_HPP

#include <memory>
#include <string>

#include "../GameEditor/include/GameEditor.hpp"

/// @brief GameEditor を使用するのを前提とした基幹クラス
class AppSystem final {
private:
	const std::string& windowTitle = "Test"; // ウィンドウ名
	const float TARGET_FPS = 60.f;           // 目標フレームレート値

	std::unique_ptr<GameEditor> gameEditor; // ゲームエディター

	/// @brief 初期化処理
	/// @return false なら失敗
	bool Init() const;
public:
	/// @brief コンストラクタ
	AppSystem();

	/// @brief デストラクタ
	~AppSystem();

	/// @brief 起動処理
	/// @return false なら失敗
	bool Boot() const;

	/// @brief 実行処理
	void Run();
};

#endif
