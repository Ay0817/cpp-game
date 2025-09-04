#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <typeindex>

#include "IAssetContainer.hpp"
#include "ClassDefine.hpp"
#include "Logger.hpp"
#include "AssetConcept.hpp"
#include "SubString.hpp"

namespace Asset {
	// @brief �S�A�Z�b�g�� Container ���Ǘ�����
	class AssetManager final {
		CLASS_SINGLETON_BODY(AssetManager)
	private:
		std::unordered_map<std::type_index, IAssetContainer&> containerMap;
	public:
		// @brief AssetManager ��o�^
		template<Concept::is_Asset T>
		void Register(IAssetContainer& container) {
			containerMap.emplace(std::type_index(typeid(T)), container);

			Logger::Log("AssetManager[" + internal::string::slicing_for_namespace(typeid(container).name()) + "]�̓o�^���������܂����B");
		}

		// @brief AssetManager ���擾
		template<Concept::is_Asset T>
		NODISCARD IAssetContainer& GetAssetManager() {
			return containerMap.at(std::type_index(typeid(T)));
		}

		// @brief ���ׂĂ� Asset ���������
		void Release();
	};
}

#endif
