#ifndef TEXTURE_LOADER_HPP
#define TEXTURE_LOADER_HPP

#include <glaze/glaze.hpp>
#include <string>
#include <vector>

#include "ClassDefine.hpp"

namespace Asset {
	// @brief サウンドを読み込む
	class TextureLoader final {
		CLASS_NONINSTANCE(TextureLoader)
	public:
		// @brief サウンドを読み込む
		// @param json ファイルのパス
		static void Load(const std::string& path);
	};
}

// @brief json ファイルから受け取るデータ要素
struct TextureItem {
	std::string name;
	std::string path;
	int allNum;
	int yNum;
	int xNum;
	float width;
	float height;
};

// @brief ルート
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
