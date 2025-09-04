#ifndef RANDOM_HPP
#define RANDOM_HPP

/// @file Random.hpp
/// @brief �����������s���N���X
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
	/// @brief �X���b�h���ƂɈ�x��������������� Mersenne Twister �����G���W�����擾����B
	/// �����V�[�h�ɂ͌��ݎ������g�p���A����X���b�h���ł͏�Ԃ��ێ������B
	/// @return �X���b�h���[�J���� std::mt19937 �C���X�^���X�̎Q�ƁB
	static std::mt19937& mt();
public:
	/// @brief �����͈̔͂��琮���^�̒l�𐶐����܂��B
	/// @tparam T �����^
	/// @param min �ŏ��l
	/// @param max �ő�l
	/// @return �������ꂽ�l
	template <Concept::is_integral T>
	NODISCARD static T Range(T min, T max) {
		auto [l, r] = math::MinMax(min, max);

		std::uniform_int_distribution<T>dis(l, r);

		return dis(mt());
	}

	/// @brief �����͈̔͂��畂�������_�^�̒l�𐶐����܂��B
	/// @tparam T ���������_�^
	/// @param min �ŏ��l
	/// @param max �ő�l
	/// @return �������ꂽ�l
	template <Concept::is_floating T>
	NODISCARD static T Range(T min, T max) {
		auto [l, r] = math::MinMax(min, max);

		std::uniform_real_distribution<T>dis(l, r);

		return dis(mt());
	}

	/// @brief �w�肳�ꂽ�V�[�h�l�ɕύX���܂��B
	/// @param seed �V�[�h�l
	static void SetSeed(unsigned int seed);
};

#endif 
