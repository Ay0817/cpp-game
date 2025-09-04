#ifndef COMPONENT_CONCEPT_HPP
#define COMPONENT_CONCEPT_HPP

#include <concepts>

/*--前方宣言--*/
class Component;

namespace Concept {
	// @brief Component class の派生クラスであるか？
	template <typename T>
	concept is_component = std::derived_from< T, Component>;
}

#endif
