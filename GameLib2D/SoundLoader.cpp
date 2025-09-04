#include <DxLib.h>
#include <memory>

#include "SoundLoader.hpp"
#include "ParseJson.hpp"
#include "Logger.hpp"

#include "Sound.hpp"
#include "SoundManager.hpp"

void Asset::SoundLoader::Load(const std::string& path) {
	const auto& data = internal::json::parse_from_json<SoundRoot>(path);

	if (!data) {
		Logger::LogError(data.error().custom_error_message);
	}

	for (const auto& item : data.value().items) {
		const auto& name = item.name;
		const auto& path = item.path;

		auto handle = LoadSoundMem(path.data());

		if (handle == -1) {
			Logger::LogError("サウンド[" + name + "]の読み込みに失敗しました。");
		}

		const auto& sound = std::make_shared<Sound>(name, path, handle);

		Logger::Log("サウンド[" + std::string(name) + "]を読み込みました。");

		SoundManager::GetInstance().Register(sound);
	}
}
