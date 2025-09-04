#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>
#include <optional>

#include "Object.hpp"
#include "Texture.hpp"

// @brief 2D �Q�[���v���C�ɂ�����X�v���C�g�I�u�W�F�N�g�������܂�
class Sprite final : public Object {
private:
	std::shared_ptr<Asset::Texture> texture;
	bool visible;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Sprite(std::string_view textureName, std::optional<bool> visible = std::nullopt);

	// @brief �f�X�g���N�^
	virtual ~Sprite() = default;

	// @brief Texture ���擾
	NODISCARD const std::shared_ptr<Asset::Texture>& GetTexture() const {
		return texture;
	}

	// @brief Texture ���Z�b�g
	void SetTexture(std::shared_ptr<Asset::Texture>& newTexture) {
		texture = std::move(newTexture);
	}

	// @brief �\����Ԃ��擾
	NODISCARD bool GetVisible() const {
		return visible;
	}

	// @brief �\����Ԃ��Z�b�g
	void SetVisible(bool state) {
		visible = state;
	}

	// @brief Sprite �𐶐�
	NODISCARD static std::shared_ptr<Sprite> Create(std::string_view textureName, std::optional<bool> visible = std::nullopt);
};

#endif
