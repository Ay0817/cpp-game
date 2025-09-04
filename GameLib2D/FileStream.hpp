#ifndef FILE_STREAM_HPP
#define FILE_STREAM_HPP

/*
    @file FileStream.hpp
    @brief �t�@�C������
    @author Ay
    @date 2025/08/03
*/

#include <string>
#include <string_view>
#include <fstream>
#include <expected>

namespace internal {
    namespace file {
        // @brief �t�@�C������ǂݍ��񂾕�������ꊇ�ŕԂ��B
        // @return ����:�ǂݍ��񂾕����� ���s:�G���[���e
        [[nodiscard]] inline std::expected<std::string, std::string> read_file(std::string_view path) {
            std::ifstream file(path.data(), std::ios::in | std::ios::binary);

            if (!file) {
                return std::unexpected("�t�@�C�����J���܂���ł���: " + std::string(path));
            }

            file.seekg(0, std::ios::end);
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);

            if (size < 0) {
                return std::unexpected("�擾�Ɏ��s���܂����B");
            }

            std::string buffer(static_cast<size_t>(size), '\0');

            if (!file.read(buffer.data(), size) || file.gcount() != size) {
                return std::unexpected("�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B");
            }

            return buffer;
        }
    }
}

#endif
