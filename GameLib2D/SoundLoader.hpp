#ifndef SOUND_LOADER_HPP
#define SOUND_LOADER_HPP

#include <glaze/glaze.hpp>
#include <string>
#include <vector>

#include "ClassDefine.hpp"

namespace Asset {
	// @brief サウンドを読み込む
	class SoundLoader final {
		CLASS_NONINSTANCE(SoundLoader)
	public:
		// @brief サウンドを読み込む
		// @param json ファイルのパス
		static void Load(const std::string& path);
	};
}

// @brief json ファイルから受け取るデータ要素
struct SoundItem {
	std::string name;
	std::string path;
};

// @brief ルート
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
