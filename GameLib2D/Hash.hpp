#ifndef HASH_HPP
#define HASH_HPP

#include <string>

namespace internal {
	namespace hash {
		// @brief ハッシュ値を生成
		[[nodiscard]] inline unsigned int create_hash_key(const std::string& key) {
			constexpr auto FNV_OFFSET_BASIS = 2166136261u;
			constexpr auto FNV_PRIME = 16777619u;

			auto hash = FNV_OFFSET_BASIS;

			for (char c : key) {
				hash ^= static_cast<uint8_t>(c);
				hash *= FNV_PRIME;
			}
			return hash;
		}
	}
}

#endif
