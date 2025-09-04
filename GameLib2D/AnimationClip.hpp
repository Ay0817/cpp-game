#ifndef ANIMATION_CLIP_HPP
#define ANIMATION_CLIP_HPP

#include <vector>

#include "Object.hpp"
#include "Sprite.hpp"

// @brief �t���[���A�j���[�V������ۑ����܂��B
class AnimationClip : public Object {
private:
	std::weak_ptr<Sprite> sprite;
	float frameRate;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 AnimationClip(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate);

	// @brief �f�X�g���N�^
	virtual ~AnimationClip() = default;

	// @brief �摜�n���h�����擾
	NODISCARD const std::weak_ptr<Sprite>& GetSprite() const {
		return sprite;
	}

	// @brief �Đ����x���擾
	NODISCARD float GetFrameRate() const {
		return frameRate;
	}
	
	// @brief AnimationClip �𐶐�
	NODISCARD static std::shared_ptr<AnimationClip> Create(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate);
};

#endif 
