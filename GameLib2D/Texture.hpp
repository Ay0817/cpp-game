#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <vector>

#include "Asset.hpp"
#include "TextureGrid.hpp"

namespace Asset {
	// @brief Base class for Texture handling.
	class Texture final : public Asset {
	private:
		int allNum;
		int yNum;
		int xNum;
		std::vector<int> handles;

		std::pair<float, float> size;
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 Texture(std::string_view name, std::string_view path, int handle, int allNum, int xNum, int yNum, const std::vector<int>& handles = {});

		// @brief デストラクタ
		virtual ~Texture() = default;

		// @brief リソース解放
		virtual void Release() override;

		// @brief 画像の分割総数を取得
		NODISCARD int GetAllNum() const {
			return allNum;
		}

		// @brief 画像の分割総数をセット
		void SetAllNum(int newAllNum) {
			allNum = newAllNum;
		}

		// @brief 画像の横向きに対する分割数を取得
		NODISCARD int GetNumX() const {
			return xNum;
		}

		// @brief 画像の横向きに対する分割数をセット
		void SetNumX(int newNumX) {
			xNum = newNumX;
		}

		// @brief 画像の縦に対する分割数を取得
		NODISCARD int GetNumY() const {
			return yNum;
		}

		// @brief 画像の縦に対する分割数をセット
		void SetNumY(int newNumY) {
			yNum = newNumY;
		}

		// @brief 画像のハンドルを取得
		NODISCARD const std::vector<int> GetHandles() const {
			return handles;
		}

		// @brief 画像のハンドルをセット
		void SetHandles(const std::vector<int>& newHandles) {
			handles = newHandles;
		}

		// @サウンド情報をセット
		void SetInfo(std::string_view name, std::string_view path, int handle, int allNum, int xNum, int yNum, const std::vector<int>& handles) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
			SetAllNum(allNum);
			SetNumX(xNum);
			SetNumY(yNum);
			SetHandles(handles);
		}

		// @brief 画像の大きさを取得
		const std::pair<float, float>& GetSize()const {
			return size;
		}

		// @brief 画像の大きさをセット
		void SetSize(float newWidth, float newHeight) {
			size.first = newWidth;
			size.second = newHeight;
		}
	};
}

#endif 
