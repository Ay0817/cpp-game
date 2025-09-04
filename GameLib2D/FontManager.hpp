#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

#include "AssetContainerBase.hpp"
#include "ClassDefine.hpp"

namespace Asset {
	// @brief �t�H���g���Ǘ�
	class FontManager final : public AssetContainerBase {
		CLASS_SINGLETON_BODY(FontManager)
	public:
		// @brief �A�Z�b�g��o�^
		virtual void Register(const std::shared_ptr<Asset>& asset) override;

		// @brief �A�Z�b�g�̉��
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) override;
	};
}

#endif 
