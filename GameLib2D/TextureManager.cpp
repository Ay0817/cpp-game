#include "TextureManager.hpp"
#include "Texture.hpp"
#include "Logger.hpp"

void Asset::TextureManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("ƒCƒ“ƒXƒ^ƒ“ƒX‚ª null ‚Å‚·B");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("‰æ‘œ‚Ì–¼‘O‚ª‹ó”’‚Å‚·");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("‰æ‘œ‚Ì“o˜^‚É¸”s‚µ‚Ü‚µ‚½B");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("‰æ‘œ[" + asset->GetName() + "]‚Ì“o˜^‚ªŠ®—¹‚µ‚Ü‚µ‚½B");
}

void Asset::TextureManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("‰æ‘œ[" + std::string(*assetName) + "]‚ğ”jŠü‚µ‚Ü‚µ‚½B");
		return;
	}

	assetMap.clear();
	Logger::Log("“o˜^‚³‚ê‚Ä‚¢‚½‰æ‘œ‚ğ‘S‚Ä”jŠü‚µ‚Ü‚µ‚½B");
}
