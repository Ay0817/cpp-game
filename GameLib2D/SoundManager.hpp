#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include "AssetContainerBase.hpp"
#include "ClassDefine.hpp"

namespace Asset {
	// @brief �T�E���h�̊Ǘ����s���N���X
	class SoundManager final : public AssetContainerBase {
		CLASS_SINGLETON_BODY(SoundManager)
	public:
		// @brief �A�Z�b�g��o�^
		virtual void Register(const std::shared_ptr<Asset>& asset) override;

		// @brief �A�Z�b�g�̉��
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) override;
	};
}

#endif 
