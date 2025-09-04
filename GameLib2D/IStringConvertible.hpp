#ifndef ISTRING_CONVERTIBLE_HPP
#define ISTRING_CONVERTIBLE_HPP

#include <string>

#include "CppVersion.hpp"

namespace System {
	class IStringConvertible {
	public:
		virtual ~IStringConvertible() = default;
		NODISCARD virtual std::string ToString() const = 0;
	};
}

#endif 
