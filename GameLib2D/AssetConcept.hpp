#ifndef ASSET_CONCEPT_HPP
#define ASSET_CONCEPT_HPP

#include <concepts>

namespace Asset {
	/*--�O���錾--*/
	class Asset;
}

namespace Concept {
	// @brief IAsset interface ���p������Ă��邩�H
	template <typename T>
	concept is_Asset = std::derived_from<T, Asset::Asset>;
}

#endif 
