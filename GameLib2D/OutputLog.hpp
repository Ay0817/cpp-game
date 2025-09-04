#ifndef OUTPUT_LOG_HPP
#define OUTPUT_LOG_HPP

#include <Windows.h>
#include <debugapi.h>
#include <string>
#include <format>
#include <print>
#include <iostream>
#include <source_location>

#include "LogType.hpp"

namespace internal {
	namespace debug {
		// @brief empty message.
		const std::string empty_message = "�󕶎���ł��B";

		// @brief debug message.
		const std::string log_type_debug = "[DEBUG] ";

		// @brief error message.
		const std::string log_type_error = "[ERROR] ";

		// @brief ���O�̎�ނɉ������������Ԃ�
		[[nodiscard]] inline const std::string& get_log_type_as_string(LogType type) noexcept {
			return type != LogType::debug ? log_type_error : log_type_debug;
		}

		// @brief �����񂪋󔒂̎��o��
		inline void output_empty_log() {
			OutputDebugStringA(empty_message.data());
		}

		// @brief �R���\�[���ɏo��
		inline void output_console(std::string_view msg) {
			if (msg.empty()) {
				output_empty_log();
			}
			std::cout << msg << std::endl;
		}

		// @brief ���O�o��
		inline void output_log(std::string_view msg) {
			if (msg.empty()) {
				output_empty_log();
			}
			OutputDebugStringA(msg.data());
		}

		// @brief ���O�o��
		inline void output_log(LogType type, std::string_view msg, const std::source_location loc) {
			auto _msg = std::format("{}[{}:{}] [{}]\n", get_log_type_as_string(type), loc.file_name(), loc.line(), msg);

			output_log(_msg.data());
		}

		// @brief ���O�o�� + �t�H�[�}�b�g�w��
		template <typename... Args>
		inline void output_log(const std::source_location& loc, LogType type, std::format_string<Args...> fmt, Args&&... args) noexcept {
			auto msg = std::format(fmt, std::forward<Args>(args)...);

			auto line = std::format("{}[{}:{}] [{}]\n", get_log_type_as_string(type), loc.file_name(), loc.line(), msg);

			output_log(line.data());
		}

		// @brief �R���\�[���֏o�� + �t�H�[�}�b�g�w��
		template <typename... Args>
		inline void output_console(std::format_string<Args...> msg, Args&&... args) {
			std::println(msg, std::forward<Args>(args)...);
		}
	}
}

#endif
