#include "SoundManager.hpp"
#include "Sound.hpp"
#include "Logger.hpp"

void Asset::SoundManager::Register(const std::shared_ptr<Asset>& asset) {
	try {
		if (asset == nullptr) {
			throw std::invalid_argument("インスタンスが null です。");
		}

		if (asset->GetName().empty()) {
			throw std::invalid_argument("サウンドの名前が空白です");
		}
	}
	catch (const std::exception& e) {
		Logger::LogError(e.what());
		Logger::LogError("サウンドの登録に失敗しました。");
	}

	assetMap.emplace(internal::hash::create_hash_key(asset->GetName()), asset);
	Logger::Log("サウンド[" + asset->GetName() + "]の登録が完了しました。");
}

void Asset::SoundManager::Release(std::optional<std::string_view> assetName) {
	if (assetName.has_value()) {
		assetMap.erase(internal::hash::create_hash_key(assetName.value().data()));
		Logger::Log("サウンド[" + std::string(*assetName) + "]を破棄しました。");
		return;
	}

	assetMap.clear();
	Logger::Log("登録されていたサウンドを全て破棄しました。");
}

