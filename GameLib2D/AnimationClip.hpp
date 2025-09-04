#ifndef ANIMATION_CLIP_HPP
#define ANIMATION_CLIP_HPP

#include <vector>

#include "Object.hpp"
#include "Sprite.hpp"

// @brief フレームアニメーションを保存します。
class AnimationClip : public Object {
private:
	std::weak_ptr<Sprite> sprite;
	float frameRate;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 AnimationClip(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate);

	// @brief デストラクタ
	virtual ~AnimationClip() = default;

	// @brief 画像ハンドルを取得
	NODISCARD const std::weak_ptr<Sprite>& GetSprite() const {
		return sprite;
	}

	// @brief 再生速度を取得
	NODISCARD float GetFrameRate() const {
		return frameRate;
	}
	
	// @brief AnimationClip を生成
	NODISCARD static std::shared_ptr<AnimationClip> Create(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate);
};

#endif 
