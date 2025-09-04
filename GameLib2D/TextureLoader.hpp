#ifndef TEXTURE_LOADER_HPP
#define TEXTURE_LOADER_HPP

#include <glaze/glaze.hpp>
#include <string>
#include <vector>

#include "ClassDefine.hpp"

namespace Asset {
	// @brief �T�E���h��ǂݍ���
	class TextureLoader final {
		CLASS_NONINSTANCE(TextureLoader)
	public:
		// @brief �T�E���h��ǂݍ���
		// @param json �t�@�C���̃p�X
		static void Load(const std::string& path);
	};
}

// @brief json �t�@�C������󂯎��f�[�^�v�f
struct TextureItem {
	std::string name;
	std::string path;
	int allNum;
	int yNum;
	int xNum;
	float width;
	float height;
};

// @brief ���[�g
struct TextureRoot {
	std::vector<TextureItem> items;
};

template<>
struct glz::meta<TextureItem> {
	static constexpr auto value = glz::object(
		"name",   &TextureItem::name,
		"path",   &TextureItem::path,
		"allNum", &TextureItem::allNum,
		"yNum",   &TextureItem::yNum,
		"xNum",   &TextureItem::xNum,
		"width",  &TextureItem::width,
		"height", &TextureItem::height
	);
};

template <>
struct glz::meta<TextureRoot> {
	static constexpr auto value = glz::object(
		"Texture", &TextureRoot::items
	);
};

#endif
