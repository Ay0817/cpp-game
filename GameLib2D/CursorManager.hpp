#ifndef CURSOR_MANAGER_HPP
#define CURSOR_MANAGER_HPP

#include "Config.hpp"
#include "Vector2.hpp"

class CursorManager final {
	CLASS_SINGLETON_BODY(CursorManager)
private:
	bool bind = false;
	bool visible = true;
public:
	/// @brief �X�V����
	void Update();

	/// @brief �E�B���h�E��̃J�[�\�����W���擾�B
	/// @return �J�[�\�����W
	NODISCARD const Vector2 GetPosition() const;

	/// @brief �w�肵�����W�փJ�[�\�����ړ��B
	/// @param pos �ړ���̍��W
	void SetPosition(const Vector2& pos);

	/// @brief �J�[�\�����\������Ă��邩�H
	/// @return true �\������Ă���A false �\������Ă��Ȃ�
	NODISCARD bool GetVisible() const;

	/// @brief �J�[�\����\�����邩�H
	/// @param state true �Ȃ�\�� false �Ȃ��\��
	void SetVisible(bool state);

	/// @brief �J�[�\�����E�B���h�E�̒��S�ɌŒ肷��B
	/// @param state 
	void SetCursorLock(bool state);
};

#define Cursor CursorManager::GetInstance()

#endif 
