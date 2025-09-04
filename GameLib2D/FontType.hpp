#ifndef FONT_TYPE_FPP
#define FONT_TYPE_FPP

// @brief フォントのタイプ
namespace FontType {
	// @brief 補正なしの生フォント。ギザギザが目立つ。
	inline constexpr int NORMAL = 0x00;

	// @brief フォントに黒縁が付く。可読性が高い。
	inline constexpr int EDGE = 0x01;

	// @brief なめらかな文字になる。輪郭はぼやけ気味。
	inline constexpr int ANTI_ALIASING = 0x02;

	// @brief より綺麗。輪郭が細くシャープ。
	inline constexpr int ANTI_ALIASING_4X4 = 0x12;

	// @brief 最も滑らか。高精細だけど重い。
	inline constexpr int ANTI_ALIASING_8X8 = 0x22;

	// @brief 滑らか＋縁取りで読みやすさ最高。
	inline constexpr int ANTI_ALIASING_EDGE_4X4 = 0x23;

	// @brief 最大品質。タイトル画面や静的演出向け。
	inline constexpr int ANTI_ALIASING_EDGE_8X8 = 0x33;

	// @brief デフォルト
	inline constexpr int DEFAULT = 0x23;
}

#endif 
