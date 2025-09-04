#ifndef UTIL_HPP
#define UTIL_HPP

#include "NumericConcept.hpp"

namespace Util {
	// @brief 2つの数値を加算して返します。
	template <Concept::is_numeric T, Concept::is_numeric U>
	constexpr auto add(T a, U b) -> decltype (a + b) {
		return a + b;
	}

	// @brief a が b より大きいか比較し結果を返します。
	template <Concept::is_numeric T, Concept::is_numeric U>
	constexpr auto greater(T a, U b) {
		return a > b;
	}

	// @brief 2つの数値が等しいか比較し結果を返します。
	template <Concept::is_numeric T, Concept::is_numeric U>
	constexpr auto equal(T a, U b) {
		return a == b;
	}

	//template <typename To, typename From>
	//constexpr To cast(const From& value) {
	//	return static_cast<To>(value);
	//}

	template <typename T>
	struct auto_caster {
		T value;

		template <typename U>
		operator U() const {
			return static_cast<U>(value);
		}
	};

	template <typename T>
	auto_caster<T> cast(const T& v) {
		return auto_caster<T>{v};
	}

	constexpr int FAILED = -1;
}

using namespace Util;

#endif
