#ifndef SOUND_LOADER_HPP
#define SOUND_LOADER_HPP

#include <glaze/glaze.hpp>
#include <string>
#include <vector>

#include "ClassDefine.hpp"

namespace Asset {
	// @brief �T�E���h��ǂݍ���
	class SoundLoader final {
		CLASS_NONINSTANCE(SoundLoader)
	public:
		// @brief �T�E���h��ǂݍ���
		// @param json �t�@�C���̃p�X
		static void Load(const std::string& path);
	};
}

// @brief json �t�@�C������󂯎��f�[�^�v�f
struct SoundItem {
	std::string name;
	std::string path;
};

// @brief ���[�g
struct SoundRoot {
	std::vector<SoundItem> items;
};

template<>
struct glz::meta<SoundItem> {
	static constexpr auto value = glz::object(
		"name", &SoundItem::name,
		"path", &SoundItem::path
	);
};

template <>
struct glz::meta<SoundRoot> {
	static constexpr auto value = glz::object(
		"Sound", &SoundRoot::items
	);
};
#endif 
