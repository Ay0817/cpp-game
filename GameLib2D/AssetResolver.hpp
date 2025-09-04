#ifndef ASSET_RESOLVER_HPP
#define ASSET_RESOLVER_HPP

#include <memory>
#include <string_view>

#include "ClassDefine.hpp"
#include "CppVersion.hpp"
#include "AssetConcept.hpp"
#include "AssetManager.hpp"

namespace Asset {
	// @brief �A�Z�b�g�̎擾���s��
	class AssetResolver final {
	CLASS_NONINSTANCE(AssetResolver)
	public:
		// @brief �A�Z�b�g���擾
		template<Concept::is_Asset T>
		static NODISCARD std::shared_ptr<T> GetAsset(std::string_view assetName) {
			auto& container = AssetManager::GetInstance().GetAssetManager<T>();
			auto asset = container.GetAsset(assetName);

			return std::dynamic_pointer_cast<T>(asset);
		}
	};
}

#endif
