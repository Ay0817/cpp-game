#ifndef RANDOM_HPP
#define RANDOM_HPP

/// @file Random.hpp
/// @brief 乱数生成を行うクラス
/// @author Ay
/// @date 2025/8/14

#include <random>
#include <chrono>

#include "Config.hpp"
#include "NumericConcept.hpp"
#include "Math.hpp"

class Random final {
	CLASS_NONINSTANCE(Random)
private:
	/// @brief スレッドごとに一度だけ初期化される Mersenne Twister 乱数エンジンを取得する。
	/// 初期シードには現在時刻を使用し、同一スレッド内では状態が保持される。
	/// @return スレッドローカルな std::mt19937 インスタンスの参照。
	static std::mt19937& mt();
public:
	/// @brief 引数の範囲から整数型の値を生成します。
	/// @tparam T 整数型
	/// @param min 最小値
	/// @param max 最大値
	/// @return 生成された値
	template <Concept::is_integral T>
	NODISCARD static T Range(T min, T max) {
		auto [l, r] = math::MinMax(min, max);

		std::uniform_int_distribution<T>dis(l, r);

		return dis(mt());
	}

	/// @brief 引数の範囲から浮動小数点型の値を生成します。
	/// @tparam T 浮動小数点型
	/// @param min 最小値
	/// @param max 最大値
	/// @return 生成された値
	template <Concept::is_floating T>
	NODISCARD static T Range(T min, T max) {
		auto [l, r] = math::MinMax(min, max);

		std::uniform_real_distribution<T>dis(l, r);

		return dis(mt());
	}

	/// @brief 指定されたシード値に変更します。
	/// @param seed シード値
	static void SetSeed(unsigned int seed);
};

#endif 
