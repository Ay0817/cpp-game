#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <utility>

#include "CppVersion.hpp"
#include "NumericConcept.hpp"

namespace math {
	// @brief ���R�ΐ��̒� e�i�萔�j
	constexpr float E = 2.71828175f;

	// @brief �~���� �΁i�萔�j
	constexpr float PI = 3.14159274f;

	// @brief 
	constexpr float EPSILON = 1e-5f;

	// @brief 
	constexpr float EPSILON_SQUARED = 1e-10f;

	// @brief �p�x f �̃T�C���i�����j��Ԃ�
	NODISCARD inline float Sin(float f) noexcept {
		return std::sin(f);
	}

	// @brief �p�x f �̃R�T�C���i�]���j��Ԃ�
	NODISCARD inline float Cos(float f) noexcept {
		return std::cos(f);
	}

	// @brief ���W�A���P�ʂ̊p�x f �̃^���W�F���g�i���ځj��Ԃ�
	NODISCARD inline float Tan(float f) noexcept {
		return std::tan(f);
	}

	// @brief f �̃A�[�N�T�C���i�t�����j��Ԃ��i�߂�l�̓��W�A���j
	NODISCARD inline float Asin(float f) noexcept {
		return std::asin(f);
	}

	// @brief f �̃A�[�N�R�T�C���i�t�]���j��Ԃ��i�߂�l�̓��W�A���j
	NODISCARD inline float Acos(float f) noexcept {
		return std::acos(f);
	}

	// @brief f �̃A�[�N�^���W�F���g�i�t���ځj��Ԃ��i�߂�l�̓��W�A���j
	NODISCARD inline float Atan(float f) noexcept {
		return std::atan(f);
	}

	// @brief y/x �̃A�[�N�^���W�F���g�i�t���ځj��Ԃ��i�߂�l�̓��W�A���j
	NODISCARD inline float Atan2(float y, float x) noexcept {
		return std::atan2(y, x);
	}

	// @brief f �̕�������Ԃ�
	NODISCARD inline float Sqrt(float f) noexcept {
		return std::sqrt(f);
	}

	// @brief float �^�̐�Βl��Ԃ�
	NODISCARD inline float Abs(float f) noexcept {
		return std::abs(f);
	}

	// @brief int �^�̐�Βl��Ԃ�
	NODISCARD inline int Abs(int value) noexcept {
		return std::abs(value);
	}

	// @brief
	NODISCARD static float Sign(float f) noexcept {
		return (f >= 0.f) ? 1.f : (-1.f);
	}

	// @brief 2 �̒l�̂�������������Ԃ�
	template <Concept::is_numeric T>
	NODISCARD constexpr T Min(T a, T b) noexcept {
		return (a < b) ? a : b;
	}

	// @brief 2 �̒l�̂����傫������Ԃ�
	template <Concept::is_numeric T>
	NODISCARD constexpr T Max(T a, T b) noexcept {
		return (a > b) ? a : b;
	}

	// @brief 
	template <Concept::is_numeric T>
	NODISCARD constexpr std::pair<T, T> MinMax(T a, T b) noexcept {
		if (a > b) {
			return { b,a };
		}
		return { a,b };
	}

	// @brief value �� min �� max �͈͓̔��Ɏ��߂ĕԂ�
	template <Concept::is_numeric T>
	NODISCARD constexpr T Clamp(T value, T min, T max) noexcept {
		if (value < min) {
			value = min;
		}
		else if (value > max) {
			value = max;
		}
		return value;
	}

	// @brief value �� 0�`1 �͈̔͂ɐ������ĕԂ�
	NODISCARD constexpr float Clamp01(float value) noexcept {
		if (value < 0.f) {
			return 0.f;
		}
		if (value > 1.f) {
			return 1.f;
		}
		return value;
	}

	// @brief a ���� b �ւ̐��`��ԁit �� 0�`1 �ɐ����j
	NODISCARD constexpr float Lerp(float a, float b, float t) noexcept {
		return a + (b - a) * Clamp01(t);
	}

	// @brief a ���� b �ւ̐��`��ԁit �͈̔͂͐������Ȃ��j
	NODISCARD constexpr float LerpUnclamped(float a, float b, float t) noexcept {
		return a + (b - a) * t;
	}
}

#endif
