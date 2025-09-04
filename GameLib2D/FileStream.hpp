#ifndef FILE_STREAM_HPP
#define FILE_STREAM_HPP

/*
    @file FileStream.hpp
    @brief ファイル操作
    @author Ay
    @date 2025/08/03
*/

#include <string>
#include <string_view>
#include <fstream>
#include <expected>

namespace internal {
    namespace file {
        // @brief ファイルから読み込んだ文字列を一括で返す。
        // @return 成功:読み込んだ文字列 失敗:エラー内容
        [[nodiscard]] inline std::expected<std::string, std::string> read_file(std::string_view path) {
            std::ifstream file(path.data(), std::ios::in | std::ios::binary);

            if (!file) {
                return std::unexpected("ファイルを開けませんでした: " + std::string(path));
            }

            file.seekg(0, std::ios::end);
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);

            if (size < 0) {
                return std::unexpected("取得に失敗しました。");
            }

            std::string buffer(static_cast<size_t>(size), '\0');

            if (!file.read(buffer.data(), size) || file.gcount() != size) {
                return std::unexpected("ファイルの読み込みに失敗しました。");
            }

            return buffer;
        }
    }
}

#endif
