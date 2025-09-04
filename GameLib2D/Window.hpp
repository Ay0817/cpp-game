#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <string_view>
#include <map>

#include "Color.hpp"

namespace Window {
	/// @brief ウィンドウの幅
	inline float width = 1280.f;

	/// @brief ウィンドウの高さ
	inline float height = 720.f;

	/// @brief 解像度
	enum class Resolution {
		HD_1920x1080,
		HD_1280x720,
		DEFAULT
	};

	/// @brief ウィンドウの見た目
	enum class Style : unsigned char {
		DEF      = 0,  // デフォルト
		NO_TITLE = 1,  // タイトルバーなし
		NO_TF    = 2,  // タイトルバーなし枠なし (No Title, No Frame)
		NO_FRAME = 3,  // 枠なし
		NONE     = 4,  // 何もなし
		NO_MIN   = 5,  // 最小化無し
		TOOL     = 6,  // ツールウインドウ
		MAX_NORM = 7,  // 最大化つき、初期状態通常サイズ
		MAX      = 8,  // 最大化つき、初期状態最大化
		DEF_NB   = 9,  // デフォルト、ボーダーなし
		MAX_NB   = 10, // 最大化つき、ボーダーなし
		NCNM     = 11  // 閉じる無し、最小化無し (No Close, No Minimize)
	};

	/// @brief 現在の解像度
	inline Resolution resolution = Resolution::DEFAULT;

	/// @brief 各解像度が持つウィンドウの大きさを保持。
	inline std::map<Resolution, std::pair<float, float>> resolutionMap = {
		{Resolution::HD_1920x1080,{1920.f,1080.f}},
		{Resolution::HD_1280x720 ,{1280.f, 720.f}},
		{Resolution::DEFAULT     ,{1280.f, 720.f}}
	};

	/// @brief ウィンドウのサイズと表示モードを設定します。
	/// @param resolution ウィンドウの幅と高さ
	/// @param fullscreen フルスクリーンモードにする場合はtrue、ウィンドウモードにする場合はfalseを指定
	void SetResolution(Resolution newResolution, bool fullscreen);

	/// @brief ウィンドウの解像度を取得。
	/// @return ウィンドウの解像度
	inline std::pair<float, float> GetResolution() {
		return resolutionMap[resolution];
	}

	/// @brief ウィンドウのタイトル名を変更します。
	/// @param title 新規タイトル名
	void SetWindowTitle(const std::string& title);

	/// @brief ウィンドウのタイトル名を変更します。
	/// @param title 新規タイトル名
	void SetWindowTitle(std::string_view title);
	
	/// @brief ウィンドウのタイトル名を変更します。
	/// @param title 新規タイトル名
	void SetWindowTitle(const char* title);

	/// @brief ウィンドウの解像度を維持したままサイズを変更します。
	/// @param rate サイズの倍率を設定 (デフォルト: 1.0)
	void SetWindowSizeExtendRate(double rate = 1.0);

	/// @brief 画面のサイズを変更できるようにするか?
	/// @param state true 変更可能、 false 変更不可
	void SetWindowSizeChangeEnable(bool state);

	/// @brief ウィンドウの背景色を変更します。
	/// @param color カラー 
	void SetWindowBackGroundColor(const Color& color);

	/// @brief ウィンドウの見た目を変更します。
	/// @param style ウィンドウの見た目
	void SetWindowStyle(Style style);

	/// @brief マウスカーソルをウィンドウ上で表示するか？
	/// @param state true 表示 false 非表示
	void SetMouseDisplay(bool state);

	/// @brief ウィンドウの中心座標を取得。
	/// @return ウィンドウの中心座標
	inline std::pair<float, float> GetWindowCenter() {
		return std::make_pair<float, float>(width / 2, height / 2);
	}

	/// @brief メインウインドウのウインドウハンドルを取得。
	/// @return メインウインドウのウインドウハンドル
	[[nodiscard]] HWND GetWindowHandle();
}

#endif 
