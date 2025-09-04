#ifndef SOUND_TYPE_HPP
#define SOUND_TYPE_HPP

#include <DxLib.h>

namespace SoundType {
	// @brief �ʏ�Đ�
	constexpr int Normal = 0x0000;
		// @brief �o�b�N�O���E���h�Đ�
	constexpr int Back = 0x0001;
	// @brief ���[�v�Đ�
	constexpr int Loop = 0x0001 | 0x0002;
}

#endif 
