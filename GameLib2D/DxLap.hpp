#ifndef DX_LAP_HPP
#define DX_LAP_HPP

#include <string>

#include "Vector2.hpp"
#include "Color.hpp"
#include "Font.hpp"
#include "AlignType.hpp"
#include "Sound.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"

namespace DxLap {
	// @brief 簡易的に文字列を表示
	// @param pos 座標
	// @param str 文字列
	// @param col 色
	void draw_string(const Vector2& pos, const std::string& str, const Color& col);

	// @brief 指定されたフォントで文字列を表示
	// @param pos 座標
	// @param str 文字列
	// @param col 色
	// @param font フォント
	void draw_string(const Vector2& pos, const std::string& str, const Color& col, const std::shared_ptr<Asset::Font>& font);

	// @brief サウンドの再生を行う
	// @param sound Sound のインスタンス
	void play_sound(const std::shared_ptr<Asset::Sound>& sound, int type);

	// @brief サウンドの再生停止する
	// @param sound Sound のインスタンス
	void stop_sound(const std::shared_ptr<Asset::Sound>& sound);

	// @brief サウンドが再生中か？
	bool is_playing(const std::shared_ptr<Asset::Sound>& sound);

	// @brief スプライトを描画する
	void draw_sprite(const std::shared_ptr<Transform>& transfrom, const std::shared_ptr<Sprite>& sprite);

	// @brief スプライトアニメーションを描画する
	void draw_sprite(const std::shared_ptr<Transform>& transfrom, int handle);

	/// @brief 空描画
	void draw_fake();
}

#endif 
