#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include <memory>

#include "Renderer.hpp"

/*--�O���錾--*/
class Sprite;

// @brief 2D �O���t�B�b�N�X�̃X�v���C�g�������_�����O
class SpriteRenderer final : public Renderer {
private:
	std::shared_ptr<Sprite> sprite;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 SpriteRenderer() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 SpriteRenderer(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~SpriteRenderer() noexcept = default;

	// @brief �`��
	virtual void Render() const override;

	// @brief Sprite ���Z�b�g����
	void SetSprite(std::shared_ptr<Sprite>& newSprite) {
		sprite = std::move(newSprite);
	}

	// @brief Sprite ���擾����
	NODISCARD const std::shared_ptr<Sprite>& GetSprite() const {
		return sprite;
	}
};

#endif 
