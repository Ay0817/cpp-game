#ifndef ASSET_CONTAINER_BASE_HPP
#define ASSET_CONTAINER_BASE_HPP

#include <unordered_map>

#include "IAssetContainer.hpp"
#include "AssetConcept.hpp"
#include "Logger.hpp"
#include "Hash.hpp"

namespace Asset {
	// @brief �A�Z�b�g���Ǘ����� Mnager �̊��N���X
	class AssetContainerBase : public IAssetContainer {
	protected:
		std::unordered_map<unsigned int, std::shared_ptr<Asset>> assetMap;
	public:
		// @�f�X�g���N�^
		virtual ~AssetContainerBase() = default;

		// @brief �A�Z�b�g��o�^
		virtual void Register(const std::shared_ptr<Asset>& asset) = 0;

		// @brief �A�Z�b�g�̉��
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) = 0;

		// @breif �A�Z�b�g�̎擾
		virtual std::shared_ptr<Asset> GetAsset(std::string_view assetName) override {
			return assetMap.at(internal::hash::create_hash_key(assetName.data()));
		}
	};
}

#endif
