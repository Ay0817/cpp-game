#ifndef FRAME_RATE_HPP
#define FRAME_RATE_HPP

/// @brief �Q�[����ʂ̃t���[�����[�g�l�� Editor ��ŕ\������B
class FrameRate final {
public:
	/// @brief �R���X�g���N�^
	[[nodiscard]] constexpr FrameRate() noexcept = default;

	/// @brief �f�X�g���N�^
	~FrameRate() noexcept = default;

	/// @brief �`�揈��
	void Draw() const;
};

#endif 
