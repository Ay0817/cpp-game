#ifndef SOUND_TYPE_HPP
#define SOUND_TYPE_HPP

#include <DxLib.h>

namespace SoundType {
	// @brief 通常再生
	constexpr int Normal = 0x0000;
		// @brief バックグラウンド再生
	constexpr int Back = 0x0001;
	// @brief ループ再生
	constexpr int Loop = 0x0001 | 0x0002;
}

#endif 
