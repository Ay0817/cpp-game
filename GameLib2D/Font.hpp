#ifndef FONT_HPP
#define FONT_HPP

#include <string>
#include <string_view>

#include "Object.hpp"
#include "Asset.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief フォントデータを持つクラス
	class Font final : public Asset {
	private:
		std::string name;
		std::string path;
		int size;
		int thick;
		int type;
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 Font(std::string_view name, std::string_view path, int handle, int size, int thick, int type);

		// @brief デストラクタ
		virtual ~Font() = default;

		// @brief リソース解放
		virtual void Release() override;

		// @brief サイズを返す
		NODISCARD int GetSize() const {
			return size;
		}

		// @brief サイズをセット
		void SetSize(int newSize) {
			size = newSize;
		}

		// @brief 太さを返す
		NODISCARD int GetThick() const {
			return thick;
		}

		// @brief 太さをセット
		void SetThick(int newThick) {
			thick = newThick;
		}

		// @brief タイプを返す
		NODISCARD int GetType() const {
			return type;
		}

		// @brief タイプをセット
		void SetType(int newType) {
			type = newType;
		}

		// @brief フォント情報をセット
		void SetInfo(std::string_view name, std::string_view path, int handle, int size, int thick, int type) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
			SetSize(size);
			SetThick(thick);
			SetType(type);
		}
	};
}

#endif
