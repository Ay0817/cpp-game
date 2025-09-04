#ifndef APP_SYSTEM_HPP
#define APP_SYSTEM_HPP

#include <memory>
#include <string>

#include "../GameEditor/include/GameEditor.hpp"

/// @brief GameEditor ���g�p����̂�O��Ƃ�����N���X
class AppSystem final {
private:
	const std::string& windowTitle = "Test"; // �E�B���h�E��
	const float TARGET_FPS = 60.f;           // �ڕW�t���[�����[�g�l

	std::unique_ptr<GameEditor> gameEditor; // �Q�[���G�f�B�^�[

	/// @brief ����������
	/// @return false �Ȃ玸�s
	bool Init() const;
public:
	/// @brief �R���X�g���N�^
	AppSystem();

	/// @brief �f�X�g���N�^
	~AppSystem();

	/// @brief �N������
	/// @return false �Ȃ玸�s
	bool Boot() const;

	/// @brief ���s����
	void Run();
};

#endif
