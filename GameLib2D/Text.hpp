#ifndef TEXT_HPP
#define TEXT_HPP

#include "Behaviour.hpp"
#include "Font.hpp"
#include "Color.hpp"

/// @brief 
class Text final : public Behaviour {
private:
	std::pair<int, int> size;
	std::string text;
	Color color;
	std::shared_ptr<Asset::Font> font;
public:
	/// @brief コンストラクタ
	NODISCARD_CPP20 Text(std::weak_ptr<GameObject> owner);

	/// @brief デストラクタ
	virtual ~Text() = default;

	/// @brief Update 前に1度だけ呼ばれる処理
	virtual void Begin() override;

	/// @brief テキストの大きさを取得
	/// @return 
	NODISCARD const std::pair<int, int>& GetSize() const {
		return size;
	}

	/// @brief テキストの大きさを設定
	/// @param newSize 値
	void SetSize(std::pair<int, int> newSize) {
		size = newSize;
	}

	/// @brief 表示するテキストを取得
	/// @return テキスト
	NODISCARD const std::string& GetText() const {
		return text;
	}

	/// @brief 表示するテキストを設定
	/// @param newText テキスト
	void SetText(const std::string& newText) {
		text = newText;
	}

	/// @brief 表示するテキストの色を取得
	/// @return テキストの色
	NODISCARD const Color& GetColor() const {
		return color;
	}

	/// @brief 表示するテキストの色を設定
	/// @param newColor 色
	void SetColor(const Color& newColor) {
		color = newColor;
	}

	/// @brief 表示するテキストのフォントを設定
	/// @param newFont フォント
	void SetFont(std::shared_ptr<Asset::Font>& newFont) {
		font = std::move(newFont);
	}

	/// @brief Text に必要な情報を設定
	/// @param newSize テキストの大きさ
	/// @param newText 表示するテキスト
	/// @param newColor 表示するテキストの色
	/// @param newFont 表示するテキストのフォント
	void SetInfo(std::pair<int, int> newSize, const std::string& newText, const Color& newColor, std::shared_ptr<Asset::Font>& newFont) {
		SetSize(newSize);
		SetText(newText);
		SetColor(newColor);
		SetFont(newFont);
	}
};

#endif
