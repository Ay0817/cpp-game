#ifndef PARSE_JSON_HPP
#define PARSE_JSON_HPP

/*
	@file ParseJson.hpp
	@brief json �t�@�C������f�[�^��ǂݎ��
	@author Ay
	@date 2025/08/03
*/

#include <glaze/glaze.hpp>
#include <string_view>

#include "FileStream.hpp"

namespace internal {
	namespace json {
		// @brief json �t�@�C������ǂݍ��񂾃f�[�^��Ԃ�
		// @return ����:�ǂݍ��񂾃f�[�^ ���s:�G���[���e
		template <glz::read_supported<glz::JSON> T>
		[[nodiscard]] inline glz::expected<T,glz::error_ctx> parse_from_json(std::string_view path) {
			if (path.empty()) {
				return glz::unexpected(glz::error_ctx{ glz::error_code::file_include_error,"�t�@�C���p�X���m�F���Ă��������B" });
			}

			auto str = file::read_file(path);

			if (!str) {
				return glz::unexpected(glz::error_ctx{ glz::error_code::file_open_failure,str.error() });
			}

			return glz::read_json<T>(str.value());
		}
	}
}

#endif
