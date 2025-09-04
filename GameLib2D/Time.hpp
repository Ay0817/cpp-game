#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <thread>

namespace internal {
	namespace time {
		/// @brief ���݂̎��Ԃ��擾�B
		/// @return ���݂̎���
		[[nodiscard]] inline float get_now_time() {
			auto now = std::chrono::high_resolution_clock::now();
			auto dur = now.time_since_epoch();

			return std::chrono::duration_cast<std::chrono::duration<float>>(dur).count();
		}
	}
}

#endif 
