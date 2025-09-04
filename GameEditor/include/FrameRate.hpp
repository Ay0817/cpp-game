#ifndef FRAME_RATE_HPP
#define FRAME_RATE_HPP

/// @brief ゲーム画面のフレームレート値を Editor 上で表示する。
class FrameRate final {
public:
	/// @brief コンストラクタ
	[[nodiscard]] constexpr FrameRate() noexcept = default;

	/// @brief デストラクタ
	~FrameRate() noexcept = default;

	/// @brief 描画処理
	void Draw() const;
};

#endif 
