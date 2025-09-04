#ifndef COMPONENT_CONCEPT_HPP
#define COMPONENT_CONCEPT_HPP

#include <concepts>

/*--�O���錾--*/
class Component;

namespace Concept {
	// @brief Component class �̔h���N���X�ł��邩�H
	template <typename T>
	concept is_component = std::derived_from< T, Component>;
}

#endif
