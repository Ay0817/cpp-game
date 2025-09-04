#include "TextureManager.hpp"
#include "Texture.hpp"
#include "Logger.hpp"

void Asset::TextureManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("�C���X�^���X�� null �ł��B");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("�摜�̖��O���󔒂ł�");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("�摜�̓o�^�Ɏ��s���܂����B");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("�摜[" + asset->GetName() + "]�̓o�^���������܂����B");
}

void Asset::TextureManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("�摜[" + std::string(*assetName) + "]��j�����܂����B");
		return;
	}

	assetMap.clear();
	Logger::Log("�o�^����Ă����摜��S�Ĕj�����܂����B");
}
