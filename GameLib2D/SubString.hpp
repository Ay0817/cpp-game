#ifndef SUB_STRING_HPP
#define SUB_STRING_HPP

#include <string>

namespace internal {
	namespace string {
		// @brief typeid(T).name ‚Åæ“¾‚µ‚½ class + ‹ó”’‚ğØ‚èæ‚é
		inline const std::string slicing_for_space(const std::string& str) {
			auto head = str.rfind(" ");

			if (head == std::string::npos) {
				return str;
			}

			return str.substr(head + 1);
		}

		// @brief typeid(T).name ‚Åæ“¾‚µ‚½ class + :‚ğØ‚èæ‚é
		inline const std::string slicing_for_namespace(const std::string& str) {
			auto head = str.rfind(":");

			if (head == std::string::npos) {
				return str;
			}

			return str.substr(head + 1);
		}
	}
}

#endif
