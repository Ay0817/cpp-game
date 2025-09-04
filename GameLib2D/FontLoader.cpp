#include <DxLib.h>
#include <memory>

#include "FontLoader.hpp"
#include "ParseJson.hpp"
#include "Logger.hpp"

#include "Font.hpp"
#include "FontManager.hpp"
#include "FontType.hpp"

void Asset::FontLoader::Load(const std::string& path) {
	const auto& data = internal::json::parse_from_json<FontRoot>(path);

	if (!data) {
		Logger::LogError(data.error().custom_error_message);
	}

	for (const auto& item : data.value().items) {
		const auto& name = item.name;
		const auto& path = item.path;
		const auto& size = item.size;
		const auto& thick = item.thick;

		auto src = AddFontResourceExA(path.data(), FR_PRIVATE, NULL);

		if (src == 0) {
			Logger::LogError("フォント[" + name + "]の読み込みに失敗しました。");
		}

		auto handle = CreateFontToHandle(name.data(), size, thick, FontType::ANTI_ALIASING);
		
		if (handle == -1) {
			Logger::LogError("フォント[" + name + "]の読み込みに失敗しました。");
		}

		const auto& font = std::make_shared<Font>(name, path, size, thick, FontType::ANTI_ALIASING, handle);

		Logger::Log("フォント[" + std::string(name) + "]を読み込みました。");

		FontManager::GetInstance().Register(font);
	}
}
