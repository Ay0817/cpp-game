#ifndef ASSET_CONTAINER_BASE_HPP
#define ASSET_CONTAINER_BASE_HPP

#include <unordered_map>

#include "IAssetContainer.hpp"
#include "AssetConcept.hpp"
#include "Logger.hpp"
#include "Hash.hpp"

namespace Asset {
	// @brief アセットを管理する Mnager の基底クラス
	class AssetContainerBase : public IAssetContainer {
	protected:
		std::unordered_map<unsigned int, std::shared_ptr<Asset>> assetMap;
	public:
		// @デストラクタ
		virtual ~AssetContainerBase() = default;

		// @brief アセットを登録
		virtual void Register(const std::shared_ptr<Asset>& asset) = 0;

		// @brief アセットの解放
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) = 0;

		// @breif アセットの取得
		virtual std::shared_ptr<Asset> GetAsset(std::string_view assetName) override {
			return assetMap.at(internal::hash::create_hash_key(assetName.data()));
		}
	};
}

#endif
