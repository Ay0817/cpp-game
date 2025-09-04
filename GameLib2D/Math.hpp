#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <utility>

#include "CppVersion.hpp"
#include "NumericConcept.hpp"

namespace math {
	// @brief 自然対数の底 e（定数）
	constexpr float E = 2.71828175f;

	// @brief 円周率 π（定数）
	constexpr float PI = 3.14159274f;

	// @brief 
	constexpr float EPSILON = 1e-5f;

	// @brief 
	constexpr float EPSILON_SQUARED = 1e-10f;

	// @brief 角度 f のサイン（正弦）を返す
	NODISCARD inline float Sin(float f) noexcept {
		return std::sin(f);
	}

	// @brief 角度 f のコサイン（余弦）を返す
	NODISCARD inline float Cos(float f) noexcept {
		return std::cos(f);
	}

	// @brief ラジアン単位の角度 f のタンジェント（正接）を返す
	NODISCARD inline float Tan(float f) noexcept {
		return std::tan(f);
	}

	// @brief f のアークサイン（逆正弦）を返す（戻り値はラジアン）
	NODISCARD inline float Asin(float f) noexcept {
		return std::asin(f);
	}

	// @brief f のアークコサイン（逆余弦）を返す（戻り値はラジアン）
	NODISCARD inline float Acos(float f) noexcept {
		return std::acos(f);
	}

	// @brief f のアークタンジェント（逆正接）を返す（戻り値はラジアン）
	NODISCARD inline float Atan(float f) noexcept {
		return std::atan(f);
	}

	// @brief y/x のアークタンジェント（逆正接）を返す（戻り値はラジアン）
	NODISCARD inline float Atan2(float y, float x) noexcept {
		return std::atan2(y, x);
	}

	// @brief f の平方根を返す
	NODISCARD inline float Sqrt(float f) noexcept {
		return std::sqrt(f);
	}

	// @brief float 型の絶対値を返す
	NODISCARD inline float Abs(float f) noexcept {
		return std::abs(f);
	}

	// @brief int 型の絶対値を返す
	NODISCARD inline int Abs(int value) noexcept {
		return std::abs(value);
	}

	// @brief
	NODISCARD static float Sign(float f) noexcept {
		return (f >= 0.f) ? 1.f : (-1.f);
	}

	// @brief 2 つの値のうち小さい方を返す
	template <Concept::is_numeric T>
	NODISCARD constexpr T Min(T a, T b) noexcept {
		return (a < b) ? a : b;
	}

	// @brief 2 つの値のうち大きい方を返す
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

	// @brief value を min と max の範囲内に収めて返す
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

	// @brief value を 0～1 の範囲に制限して返す
	NODISCARD constexpr float Clamp01(float value) noexcept {
		if (value < 0.f) {
			return 0.f;
		}
		if (value > 1.f) {
			return 1.f;
		}
		return value;
	}

	// @brief a から b への線形補間（t を 0～1 に制限）
	NODISCARD constexpr float Lerp(float a, float b, float t) noexcept {
		return a + (b - a) * Clamp01(t);
	}

	// @brief a から b への線形補間（t の範囲は制限しない）
	NODISCARD constexpr float LerpUnclamped(float a, float b, float t) noexcept {
		return a + (b - a) * t;
	}
}

#endif
