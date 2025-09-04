#include "SoundManager.hpp"
#include "Sound.hpp"
#include "Logger.hpp"

void Asset::SoundManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("�C���X�^���X�� null �ł��B");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("�T�E���h�̖��O���󔒂ł�");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("�T�E���h�̓o�^�Ɏ��s���܂����B");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("�T�E���h[" + asset->GetName() + "]�̓o�^���������܂����B");
}

void Asset::SoundManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("�T�E���h[" + std::string(*assetName) + "]��j�����܂����B");
		return;
	}

	assetMap.clear();
	Logger::Log("�o�^����Ă����T�E���h��S�Ĕj�����܂����B");
}

