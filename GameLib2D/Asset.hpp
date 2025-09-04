#ifndef ASSET_HPP
#define ASSET_HPP

#include "Object.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief アセットの基底クラス
	class Asset : public Object {
	protected:
		int handle;
		std::string path;
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 Asset(std::string_view name, std::string_view path, int handle);

		// @brief デストラクタ
		virtual ~Asset();

		// @brief ファイルパスを返す
		NODISCARD const std::string& GetPath() const {
			return path;
		}

		// @brief ファイルパスをセット
		void SetPath(std::string_view newPath) {
			path = newPath;
		}

		// @brief ハンドルを返す
		NODISCARD int GetHandle() const {
			return handle;
		}

		// @brief ハンドルをセット
		void SetHandle(int newHandle) {
			handle = newHandle;
		}

		// @brief リソース解放
		virtual void Release() {}
	};
}

#endif 
