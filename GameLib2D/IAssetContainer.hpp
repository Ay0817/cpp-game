#ifndef IASSET_CONTAINER_HPP
#define IASSET_CONTAINER_HPP

#include <optional>
#include <memory>
#include <string_view>

namespace Asset {
	/*--�O���錾--*/
	class Asset;

	// @brief �A�Z�b�g�Ǘ����s���N���X�̃C���^�[�t�F�[�X
	class IAssetContainer {
	public:
		// @brief �f�X�g���N�^
		virtual ~IAssetContainer() = default;

		// @brief �A�Z�b�g���擾
		virtual std::shared_ptr<Asset> GetAsset(std::string_view assetName) = 0;

		// @brief �A�Z�b�g�����
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) = 0;
	};
}

#endif 
