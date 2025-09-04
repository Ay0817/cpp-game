#ifndef CORE_HPP
#define CORE_HPP

/// @brief GameEditorを使用する方針のため、一旦廃止。
namespace core {
	// @brief 
	bool Init();

	// @brief 
	void Awake();

	// @brief 
	void Begin();

	// @brief メインループ
	bool Loop();

	// @brief 更新処理
	void Update();

	// @brief 描画処理
	void Render();

	// @brief 
	void End();
}

#endif 
