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
			Logger::LogError("�T�E���h[" + name + "]�̓ǂݍ��݂Ɏ��s���܂����B");
		}

		const auto& sound = std::make_shared<Sound>(name, path, handle);

		Logger::Log("�T�E���h[" + std::string(name) + "]��ǂݍ��݂܂����B");

		SoundManager::GetInstance().Register(sound);
	}
}
