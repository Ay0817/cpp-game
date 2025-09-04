#ifndef GAME_EDITOR_HPP
#define GAME_EDITOR_HPP

#include <string>
#include <memory>
#include <vector>

#include "FrameRate.hpp"
#include "Hierarchy.hpp"
#include "Inspector.hpp"
#include "AddObjectNode.hpp"

/// @brief �Q�[���J���p�̃G�f�B�^�@�\��񋟂���N���X�ł��B
/// @brief �V�[���ւ̊��A�I�u�W�F�N�g�̊Ǘ������s���܂��B
class GameEditor final {
private:
	std::shared_ptr<Hierarchy> hierarchy;         // �V�[�����I�u�W�F�N�g�̊K�w���Ǘ��E�\��
	std::unique_ptr<Inspector> inspector;         // �I�u�W�F�N�g�����l��\���E�ύX
	std::unique_ptr<FrameRate> frameRate;         // �t���[�����[�g��\��
	std::unique_ptr<AddObjectNode> addObjectNode; // �V�����I�u�W�F�N�g�m�[�h��ǉ�����UI
public:
	/// @brief ����������
	/// @return ���s������ false
	[[nodiscard]] bool Init();

	/// @brief �X�V����
	void Update();

	/// @brief �`�揈��
	void Render() const;

	/// @brief �I��������
	void End();
};

#endif 
