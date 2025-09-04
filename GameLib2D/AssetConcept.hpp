#ifndef ASSET_CONCEPT_HPP
#define ASSET_CONCEPT_HPP

#include <concepts>

namespace Asset {
	/*--‘O•ûéŒ¾--*/
	class Asset;
}

namespace Concept {
	// @brief IAsset interface ‚ªŒp³‚³‚ê‚Ä‚¢‚é‚©H
	template <typename T>
	concept is_Asset = std::derived_from<T, Asset::Asset>;
}

#endif 
