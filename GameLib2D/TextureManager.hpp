#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "AssetContainerBase.hpp"
#include "ClassDefine.hpp"

namespace Asset{
	class TextureManager final : public AssetContainerBase {
		CLASS_SINGLETON_BODY(TextureManager)
	public:
		// @brief アセットを登録
		virtual void Register(const std::shared_ptr<Asset>& asset) override;

		// @brief アセットの解放
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) override;
	};
}

#endif 
