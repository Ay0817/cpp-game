#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>
#include <optional>

#include "Object.hpp"
#include "Texture.hpp"

// @brief 2D ゲームプレイにおけるスプライトオブジェクトを示します
class Sprite final : public Object {
private:
	std::shared_ptr<Asset::Texture> texture;
	bool visible;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Sprite(std::string_view textureName, std::optional<bool> visible = std::nullopt);

	// @brief デストラクタ
	virtual ~Sprite() = default;

	// @brief Texture を取得
	NODISCARD const std::shared_ptr<Asset::Texture>& GetTexture() const {
		return texture;
	}

	// @brief Texture をセット
	void SetTexture(std::shared_ptr<Asset::Texture>& newTexture) {
		texture = std::move(newTexture);
	}

	// @brief 表示状態を取得
	NODISCARD bool GetVisible() const {
		return visible;
	}

	// @brief 表示状態をセット
	void SetVisible(bool state) {
		visible = state;
	}

	// @brief Sprite を生成
	NODISCARD static std::shared_ptr<Sprite> Create(std::string_view textureName, std::optional<bool> visible = std::nullopt);
};

#endif
