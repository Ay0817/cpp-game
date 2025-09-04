#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include "AssetContainerBase.hpp"
#include "ClassDefine.hpp"

namespace Asset {
	// @brief サウンドの管理を行うクラス
	class SoundManager final : public AssetContainerBase {
		CLASS_SINGLETON_BODY(SoundManager)
	public:
		// @brief アセットを登録
		virtual void Register(const std::shared_ptr<Asset>& asset) override;

		// @brief アセットの解放
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) override;
	};
}

#endif 
