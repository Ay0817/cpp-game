#include "FontManager.hpp"
#include "Font.hpp"
#include "Logger.hpp"

void Asset::FontManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("インスタンスが null です。");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("フォントの名前が空白です");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("フォントの登録に失敗しました。");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("フォント[" + asset->GetName() + "]の登録が完了しました。");
}

void Asset::FontManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("フォント[" + std::string(*assetName) + "]を破棄しました。");
		return;
	}

	assetMap.clear();
	Logger::Log("登録されていたフォントを全て破棄しました。");
}
