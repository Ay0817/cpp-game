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
	/// @brief �R���X�g���N�^
	NODISCARD_CPP20 Text(std::weak_ptr<GameObject> owner);

	/// @brief �f�X�g���N�^
	virtual ~Text() = default;

	/// @brief Update �O��1�x�����Ă΂�鏈��
	virtual void Begin() override;

	/// @brief �e�L�X�g�̑傫�����擾
	/// @return 
	NODISCARD const std::pair<int, int>& GetSize() const {
		return size;
	}

	/// @brief �e�L�X�g�̑傫����ݒ�
	/// @param newSize �l
	void SetSize(std::pair<int, int> newSize) {
		size = newSize;
	}

	/// @brief �\������e�L�X�g���擾
	/// @return �e�L�X�g
	NODISCARD const std::string& GetText() const {
		return text;
	}

	/// @brief �\������e�L�X�g��ݒ�
	/// @param newText �e�L�X�g
	void SetText(const std::string& newText) {
		text = newText;
	}

	/// @brief �\������e�L�X�g�̐F���擾
	/// @return �e�L�X�g�̐F
	NODISCARD const Color& GetColor() const {
		return color;
	}

	/// @brief �\������e�L�X�g�̐F��ݒ�
	/// @param newColor �F
	void SetColor(const Color& newColor) {
		color = newColor;
	}

	/// @brief �\������e�L�X�g�̃t�H���g��ݒ�
	/// @param newFont �t�H���g
	void SetFont(std::shared_ptr<Asset::Font>& newFont) {
		font = std::move(newFont);
	}

	/// @brief Text �ɕK�v�ȏ���ݒ�
	/// @param newSize �e�L�X�g�̑傫��
	/// @param newText �\������e�L�X�g
	/// @param newColor �\������e�L�X�g�̐F
	/// @param newFont �\������e�L�X�g�̃t�H���g
	void SetInfo(std::pair<int, int> newSize, const std::string& newText, const Color& newColor, std::shared_ptr<Asset::Font>& newFont) {
		SetSize(newSize);
		SetText(newText);
		SetColor(newColor);
		SetFont(newFont);
	}
};

#endif
