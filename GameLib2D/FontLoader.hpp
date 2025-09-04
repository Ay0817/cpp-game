#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include <glaze/glaze.hpp>
#include <string>
#include <vector>

#include "ClassDefine.hpp"

namespace Asset {
	// @brief �t�H���g��ǂݍ���
	class FontLoader final {
		CLASS_NONINSTANCE(FontLoader)
	public:
		// @brief �t�H���g��ǂݍ���
		// @param json �t�@�C���̃p�X
		static void Load(const std::string& path);
	};
}

// @brief json �t�@�C������󂯎��f�[�^�v�f
struct FontItem {
	std::string name;
	std::string path;
	int size;
	int thick;
};

// @brief ���[�g
struct FontRoot {
	std::vector<FontItem> items;
};

template<>
struct glz::meta<FontItem> {
	static constexpr auto value = glz::object(
		"name", &FontItem::name,
		"path", &FontItem::path,
		"size", &FontItem::size,
		"thick", &FontItem::thick
	);
};

template <>
struct glz::meta<FontRoot> {
	static constexpr auto value = glz::object(
		"Font", &FontRoot::items
	);
};

#endif
