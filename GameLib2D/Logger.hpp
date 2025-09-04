#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <string_view>
#include <source_location>

#include "OutputLog.hpp"
#include "IStringConvertible.hpp"
#include "NumericConcept.hpp"

// @brief 
#define AY_DEBUG

// @brief ���O�̏o�͂��s���B
class Logger final {
private:
	Logger() = delete;
public:
	// @brief ���O�o��
	template <Concept::is_numeric T>
	static void Log(T value, const std::source_location location = std::source_location::current()) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(internal::debug::LogType::debug, std::to_string(value), location);
#endif
	}

	// @brief ���O�o��
	static void Log(std::string_view msg, const std::source_location location = std::source_location::current()) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(internal::debug::LogType::debug, msg, location);
#endif
	}

	// @brief ���O�o��
	static void Log(const System::IStringConvertible& sc, const std::source_location location = std::source_location::current()) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(internal::debug::LogType::debug, sc.ToString(), location);
#endif
	}

	// @brief ���O�o�� + �t�H�[�}�b�g�w��
	template <typename... Args>
	static void LogF(const std::source_location& location, std::format_string<Args...> fmt, Args&&... args) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(location, internal::debug::LogType::debug, fmt, std::forward<Args>(args)...);
#endif
	}

	// @brief ���O�o�� + �t�H�[�}�b�g�w��
#define LogF(fmt, ...) Logger::LogF(std::source_location::current(), fmt, ##__VA_ARGS__)

// @brief �G���[���O�o��
	static void LogError(std::string_view msg, const std::source_location location = std::source_location::current()) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(internal::debug::LogType::error, msg, location);
#endif
	}

	// @brief �G���[���O�o�� + �t�H�[�}�b�g�w��
	template <typename... Args>
	static void LogErrorF(const std::source_location& location, std::format_string<Args...> fmt, Args&&... args) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_log(location, internal::debug::LogType::error, fmt, std::forward<Args>(args)...);
#endif
	}

	// @brief �G���[���O�o�� + �t�H�[�}�b�g�w��
#define LogErrorF(fmt, ...) Logger::LogErrorF(std::source_location::current(), fmt, ##__VA_ARGS__)

// @brief �R���\�[���o��
	template <Concept::is_numeric T>
	static void LogConsole(T value) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_console(std::to_string(value));
#endif
	}

	// @brief �R���\�[���o��
	static void LogConsole(std::string_view msg) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_console(msg);
#endif
	}

	// @brief �R���\�[���o��
	static void LogConsole(const System::IStringConvertible& sc) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_console(sc.ToString());
#endif
	}

	// @brief �R���\�[���o�� + �t�H�[�}�b�g�w��
	template <typename... Args>
	static void LogConsole(std::format_string<Args...> fmt, Args&&... args) noexcept {
#ifdef AY_DEBUG
		internal::debug::output_console(fmt, std::forward<Args>(args)...);
#endif
	}
};

#endif
