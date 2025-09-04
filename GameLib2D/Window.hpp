#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <string_view>
#include <map>

#include "Color.hpp"

namespace Window {
	/// @brief �E�B���h�E�̕�
	inline float width = 1280.f;

	/// @brief �E�B���h�E�̍���
	inline float height = 720.f;

	/// @brief �𑜓x
	enum class Resolution {
		HD_1920x1080,
		HD_1280x720,
		DEFAULT
	};

	/// @brief �E�B���h�E�̌�����
	enum class Style : unsigned char {
		DEF      = 0,  // �f�t�H���g
		NO_TITLE = 1,  // �^�C�g���o�[�Ȃ�
		NO_TF    = 2,  // �^�C�g���o�[�Ȃ��g�Ȃ� (No Title, No Frame)
		NO_FRAME = 3,  // �g�Ȃ�
		NONE     = 4,  // �����Ȃ�
		NO_MIN   = 5,  // �ŏ�������
		TOOL     = 6,  // �c�[���E�C���h�E
		MAX_NORM = 7,  // �ő剻���A������Ԓʏ�T�C�Y
		MAX      = 8,  // �ő剻���A������ԍő剻
		DEF_NB   = 9,  // �f�t�H���g�A�{�[�_�[�Ȃ�
		MAX_NB   = 10, // �ő剻���A�{�[�_�[�Ȃ�
		NCNM     = 11  // ���閳���A�ŏ������� (No Close, No Minimize)
	};

	/// @brief ���݂̉𑜓x
	inline Resolution resolution = Resolution::DEFAULT;

	/// @brief �e�𑜓x�����E�B���h�E�̑傫����ێ��B
	inline std::map<Resolution, std::pair<float, float>> resolutionMap = {
		{Resolution::HD_1920x1080,{1920.f,1080.f}},
		{Resolution::HD_1280x720 ,{1280.f, 720.f}},
		{Resolution::DEFAULT     ,{1280.f, 720.f}}
	};

	/// @brief �E�B���h�E�̃T�C�Y�ƕ\�����[�h��ݒ肵�܂��B
	/// @param resolution �E�B���h�E�̕��ƍ���
	/// @param fullscreen �t���X�N���[�����[�h�ɂ���ꍇ��true�A�E�B���h�E���[�h�ɂ���ꍇ��false���w��
	void SetResolution(Resolution newResolution, bool fullscreen);

	/// @brief �E�B���h�E�̉𑜓x���擾�B
	/// @return �E�B���h�E�̉𑜓x
	inline std::pair<float, float> GetResolution() {
		return resolutionMap[resolution];
	}

	/// @brief �E�B���h�E�̃^�C�g������ύX���܂��B
	/// @param title �V�K�^�C�g����
	void SetWindowTitle(const std::string& title);

	/// @brief �E�B���h�E�̃^�C�g������ύX���܂��B
	/// @param title �V�K�^�C�g����
	void SetWindowTitle(std::string_view title);
	
	/// @brief �E�B���h�E�̃^�C�g������ύX���܂��B
	/// @param title �V�K�^�C�g����
	void SetWindowTitle(const char* title);

	/// @brief �E�B���h�E�̉𑜓x���ێ������܂܃T�C�Y��ύX���܂��B
	/// @param rate �T�C�Y�̔{����ݒ� (�f�t�H���g: 1.0)
	void SetWindowSizeExtendRate(double rate = 1.0);

	/// @brief ��ʂ̃T�C�Y��ύX�ł���悤�ɂ��邩?
	/// @param state true �ύX�\�A false �ύX�s��
	void SetWindowSizeChangeEnable(bool state);

	/// @brief �E�B���h�E�̔w�i�F��ύX���܂��B
	/// @param color �J���[ 
	void SetWindowBackGroundColor(const Color& color);

	/// @brief �E�B���h�E�̌����ڂ�ύX���܂��B
	/// @param style �E�B���h�E�̌�����
	void SetWindowStyle(Style style);

	/// @brief �}�E�X�J�[�\�����E�B���h�E��ŕ\�����邩�H
	/// @param state true �\�� false ��\��
	void SetMouseDisplay(bool state);

	/// @brief �E�B���h�E�̒��S���W���擾�B
	/// @return �E�B���h�E�̒��S���W
	inline std::pair<float, float> GetWindowCenter() {
		return std::make_pair<float, float>(width / 2, height / 2);
	}

	/// @brief ���C���E�C���h�E�̃E�C���h�E�n���h�����擾�B
	/// @return ���C���E�C���h�E�̃E�C���h�E�n���h��
	[[nodiscard]] HWND GetWindowHandle();
}

#endif 
