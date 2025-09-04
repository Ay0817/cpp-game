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
	// @brief �ȈՓI�ɕ������\��
	// @param pos ���W
	// @param str ������
	// @param col �F
	void draw_string(const Vector2& pos, const std::string& str, const Color& col);

	// @brief �w�肳�ꂽ�t�H���g�ŕ������\��
	// @param pos ���W
	// @param str ������
	// @param col �F
	// @param font �t�H���g
	void draw_string(const Vector2& pos, const std::string& str, const Color& col, const std::shared_ptr<Asset::Font>& font);

	// @brief �T�E���h�̍Đ����s��
	// @param sound Sound �̃C���X�^���X
	void play_sound(const std::shared_ptr<Asset::Sound>& sound, int type);

	// @brief �T�E���h�̍Đ���~����
	// @param sound Sound �̃C���X�^���X
	void stop_sound(const std::shared_ptr<Asset::Sound>& sound);

	// @brief �T�E���h���Đ������H
	bool is_playing(const std::shared_ptr<Asset::Sound>& sound);

	// @brief �X�v���C�g��`�悷��
	void draw_sprite(const std::shared_ptr<Transform>& transfrom, const std::shared_ptr<Sprite>& sprite);

	// @brief �X�v���C�g�A�j���[�V������`�悷��
	void draw_sprite(const std::shared_ptr<Transform>& transfrom, int handle);

	/// @brief ��`��
	void draw_fake();
}

#endif 
