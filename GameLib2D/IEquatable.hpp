#ifndef IEQUATABLE_HPP
#define IEQUATABLE_HPP

#include "CppVersion.hpp"

namespace System {
	template <class T>
	class IEquatable {
	public:
		virtual ~IEquatable() = default;
		NODISCARD virtual bool Equals(const T& other) const = 0;
	};
}

#endif 
