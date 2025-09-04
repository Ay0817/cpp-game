#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include <memory>

#include "Renderer.hpp"

/*--前方宣言--*/
class Sprite;

// @brief 2D グラフィックスのスプライトをレンダリング
class SpriteRenderer final : public Renderer {
private:
	std::shared_ptr<Sprite> sprite;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 SpriteRenderer() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 SpriteRenderer(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~SpriteRenderer() noexcept = default;

	// @brief 描画
	virtual void Render() const override;

	// @brief Sprite をセットする
	void SetSprite(std::shared_ptr<Sprite>& newSprite) {
		sprite = std::move(newSprite);
	}

	// @brief Sprite を取得する
	NODISCARD const std::shared_ptr<Sprite>& GetSprite() const {
		return sprite;
	}
};

#endif 
