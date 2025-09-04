#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

#include "AssetContainerBase.hpp"
#include "ClassDefine.hpp"

namespace Asset {
	// @brief フォントを管理
	class FontManager final : public AssetContainerBase {
		CLASS_SINGLETON_BODY(FontManager)
	public:
		// @brief アセットを登録
		virtual void Register(const std::shared_ptr<Asset>& asset) override;

		// @brief アセットの解放
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) override;
	};
}

#endif 
