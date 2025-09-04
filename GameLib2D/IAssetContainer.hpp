#ifndef IASSET_CONTAINER_HPP
#define IASSET_CONTAINER_HPP

#include <optional>
#include <memory>
#include <string_view>

namespace Asset {
	/*--前方宣言--*/
	class Asset;

	// @brief アセット管理を行うクラスのインターフェース
	class IAssetContainer {
	public:
		// @brief デストラクタ
		virtual ~IAssetContainer() = default;

		// @brief アセットを取得
		virtual std::shared_ptr<Asset> GetAsset(std::string_view assetName) = 0;

		// @brief アセットを解放
		virtual void Release(std::optional<std::string_view> assetName = std::nullopt) = 0;
	};
}

#endif 
