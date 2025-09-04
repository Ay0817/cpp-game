#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>

#include "Object.hpp"
#include "Asset.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief サウンドデータを持つクラス
	class Sound : public Asset {
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 Sound(std::string_view name, std::string_view path, int handle);

		// @brief デストラクタ
		virtual ~Sound() = default;

		// @brief リソース解放
		virtual void Release() override;

		// @サウンド情報をセット
		void SetInfo(std::string_view name, std::string_view path, int handle) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
		}
	};
}

#endif
