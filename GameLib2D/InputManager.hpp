#ifndef INPUT_HPP
#define INPUT_HPP

#include <DxLib.h>
#include <array>
#include <utility>

#include "Vector2.hpp"
#include "Config.hpp"

// @brief  �Ή����Ă���L�[
enum class Keys : uint8_t {
	A = 0x1e,
	B = 0x30,
	C = 0x2e,
	D = 0x20,
	E = 0x12,
	F = 0x21,
	G = 0x22,
	H = 0x23,
	I = 0x17,
	J = 0x24,
	K = 0x25,
	L = 0x26,
	M = 0x32,
	N = 0x31,
	O = 0x18,
	P = 0x19,
	Q = 0x10,
	R = 0x13,
	S = 0x1f,
	T = 0x14,
	U = 0x16,
	V = 0x2f,
	W = 0x11,
	X = 0x2d,
	Y = 0x15,
	Z = 0x2c,

	Alpha1 = 0x02,
	Alpha2 = 0x03,
	Alpha3 = 0x04,
	Alpha4 = 0x05,
	Alpha5 = 0x06,
	Alpha6 = 0x07,
	Alpha7 = 0x08,
	Alpha8 = 0x09,
	Alpha9 = 0x0a,
	Alpha0 = 0x0b,

	ESC = 0x01,
	SPACE = 0x39,
	LSHIT = 0x2a,
	RSHIT = 0x36,
	ENTER = 0x1c,

	UpArrow = 0xc8,
	DownArrow = 0xd0,
	RightArrow = 0xcd,
	LeftArrow = 0xcb,
};

// @brief �Ή����Ă���}�E�X�{�^��
enum class MButtons : uint8_t {
	Left = 0,
	Right = 1,
	Mid = 2
};

// @brief �L�[���͂��Ď�
class InputManager final {
	CLASS_SINGLETON_BODY(InputManager)
private:
	enum class State : uint8_t {
		RELEASE   = 0, // ���͂���Ă��Ȃ�
		PRESSING  = 1, // ���͂��ꂽ�u��
		PRESS     = 2, // ���͂���Ă���
		RELEASING = 3  // �����ꂽ�u��
	};

	std::array<State, 256> keyInputs = {};
	std::array<State, 3> mouseInputs = {};
	Vector2 position = Vector2::zero();
	Vector2 delta = Vector2::zero();

	// @brief ��Ԃ��擾
	NODISCARD State next_state(State current, bool pressd) const noexcept;
public:
	// @brief �X�V����
	void Update();
	
	// @param key ������Ă��邩�m�F�������L�[
	// @return �L�[�������Ă���ԁAtrue ��Ԃ�
	NODISCARD bool GetKey(Keys key) const {
		return keyInputs[std::to_underlying(key)] == State::PRESS;
	}
	
	// @param key ������Ă��邩�m�F�������L�[
	// @return �L�[���������t���[���̊Ԃ����Atrue ��Ԃ�
	NODISCARD bool GetKeyDown(Keys key) const {
		return keyInputs[std::to_underlying(key)] == State::PRESSING;
	}
	
	// @param key ������Ă��邩�m�F�������L�[
	// @return �L�[�𗣂����t���[���̊Ԃ����Atrue ��Ԃ�
	NODISCARD bool GetKeyUp(Keys key) const {
		return keyInputs[std::to_underlying(key)] == State::RELEASING;
	}
	
	// @param button ������Ă��邩�m�F�������{�^��
	// @return �}�E�X�{�^����������Ă��邩�ǂ�����Ԃ�
	NODISCARD bool GetMouseButton(MButtons button) const {
		return mouseInputs[std::to_underlying(button)] == State::PRESS;
	}

	// @param button ������Ă��邩�m�F�������{�^��
	// @return �}�E�X�{�^�����������t���[���̊Ԃ��� true ��Ԃ�
	NODISCARD bool GetMouseButtonDown(MButtons button) const {
		return mouseInputs[std::to_underlying(button)] == State::PRESSING;
	}
	
	// @param button ������Ă��邩�m�F�������{�^��
	// @return �}�E�X�{�^���𗣂����t���[���̊Ԃ��� true ��Ԃ�
	NODISCARD bool GetMouseButtonUp(MButtons button) const {
		return mouseInputs[std::to_underlying(button)] == State::RELEASING;
	}
	
	// @return ���݂̃}�E�X�J�[�\�����W��Ԃ�
	NODISCARD const Vector2& GetMousePosition() const {
		return position;
	}

	// @return �}�E�X�J�[�\�����W�̈ړ��ʂ�Ԃ�
	NODISCARD const Vector2& GetMouseDelta() const {
		return delta;
	}
};

#define Input InputManager::GetInstance()

#endif
