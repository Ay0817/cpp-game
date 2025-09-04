#ifndef TIME_MANAGER_HPP
#define TIME_MANAGER_HPP

/// @file TimeManager.hpp
/// @brief ���ԏ����֌W
/// @author Ay
/// @date 2025/8/14

#include "Config.hpp"

/// @brief ���ԏ����֌W�N���X
class TimeManager final {
	CLASS_SINGLETON_BODY(TimeManager)
private:
	float now;
	float last;
	float timeScale;
public:
	/// @brief ������
	static void Init();

	/// @brief �X�V����
	void Update();

	/// @brief ���݂̎��Ԃ��擾�B
	/// @return ���݂̎���
	NODISCARD float GetNowTime() const noexcept {
		return now;
	}

	/// @brief 1�t���[���O�̎��Ԃ��擾�B
	/// @return 1�t���[���O�̎���
	NODISCARD float GetLastTime() const noexcept {
		return last;
	}

	/// @brief �O�t���[������̌o�ߎ��Ԃ��擾�B
	/// @return �O�t���[�����猻�݂̃t���[���܂ł̌o�ߎ���
	NODISCARD float GetDeltaTime() const noexcept {
		return now - last;
	}

	/// @brief �O�t���[������̌o�ߎ��ԂɃX�P�[�����|�����f���^�^�C�����擾�B
	/// @return �O�t���[�����猻�݃t���[���܂ł̌o�ߎ��Ԃ� timeScale ���|�����l
	NODISCARD float GetScaledDeltaTime() const noexcept {
		return (now - last) * timeScale;
	}

	/// @brief �Q�[���S�̂̑��x��ύX
	/// @param scale �ݒ肷�鑬�x
	void SetTimeScale(float scale) noexcept {
		timeScale = scale;
	}
};

#define Time TimeManager::GetInstance()

#endif 
