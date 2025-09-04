#ifndef FONT_TYPE_FPP
#define FONT_TYPE_FPP

// @brief �t�H���g�̃^�C�v
namespace FontType {
	// @brief �␳�Ȃ��̐��t�H���g�B�M�U�M�U���ڗ��B
	inline constexpr int NORMAL = 0x00;

	// @brief �t�H���g�ɍ������t���B�ǐ��������B
	inline constexpr int EDGE = 0x01;

	// @brief �Ȃ߂炩�ȕ����ɂȂ�B�֊s�͂ڂ₯�C���B
	inline constexpr int ANTI_ALIASING = 0x02;

	// @brief ����Y��B�֊s���ׂ��V���[�v�B
	inline constexpr int ANTI_ALIASING_4X4 = 0x12;

	// @brief �ł����炩�B�����ׂ����Ǐd���B
	inline constexpr int ANTI_ALIASING_8X8 = 0x22;

	// @brief ���炩�{�����œǂ݂₷���ō��B
	inline constexpr int ANTI_ALIASING_EDGE_4X4 = 0x23;

	// @brief �ő�i���B�^�C�g����ʂ�ÓI���o�����B
	inline constexpr int ANTI_ALIASING_EDGE_8X8 = 0x33;

	// @brief �f�t�H���g
	inline constexpr int DEFAULT = 0x23;
}

#endif 
