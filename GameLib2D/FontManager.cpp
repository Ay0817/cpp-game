#include "FontManager.hpp"
#include "Font.hpp"
#include "Logger.hpp"

void Asset::FontManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("�C���X�^���X�� null �ł��B");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("�t�H���g�̖��O���󔒂ł�");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("�t�H���g�̓o�^�Ɏ��s���܂����B");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("�t�H���g[" + asset->GetName() + "]�̓o�^���������܂����B");
}

void Asset::FontManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("�t�H���g[" + std::string(*assetName) + "]��j�����܂����B");
		return;
	}

	assetMap.clear();
	Logger::Log("�o�^����Ă����t�H���g��S�Ĕj�����܂����B");
}
