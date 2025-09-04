#ifndef INSPECTOR_HPP
#define INSPECTOR_HPP

#include <string>
#include <memory>
#include <unordered_map>

/*�O���錾*/
class GameObject;

/// @brief Editor ��� GameObject �����l��\������B
/// @brief �l����͂��邱�ƂőΏۂ� GameObejct �̒l��ύX���邱�Ƃ��ł���B 
class Inspector final {
private:
	float rate;       // �{��
	std::string name; // ���ږ�

	char x[10];     // x ���W
	char y[10];     // y ���W
	char scale[10]; // �X�P�[��
	char angle[10]; // �p�x

	unsigned int prevID; // �O��I�����ꂽ ID
	float prevX;         // �O��� x ���W�̒l
	float prevY;         // �O��� y ���W�̒l
	float prevScale;     // �O��� scale �̒l
	float prevAngle;     // �O��� angle �̒l

	/// @brief 
	/// @param x �V���� x ���W
	/// @param y �V���� y ���W
	/// @param scale �V���ȃX�P�[��
	/// @param angle �V���Ȋp�x
	/// @param obj �l��ύX���� GameObject �̎Q�Ɛ�
	void value_update(float x, float y, float scale, float angle, const std::shared_ptr<GameObject>& obj) const;

	/// @brief �l��ύX����O�ɃZ�b�g�A�b�v���s���B
	/// @param obj �l��ύX���� GameObject �̎Q�Ɛ�
	void value_setup(const std::shared_ptr<GameObject>& obj);

	/// @brief �z��̗v�f���󂾂����Ƃ��p�̑΍�
	/// @param buf �Ώۂ̃o�b�t�@�[
	void sanitize_buffer(char* buf);
public:
	/// @brief �R���X�g���N�^
	[[nodiscard]] Inspector();

	/// @brief �`�揈��
	/// @param obj Inspector �ɕ\������� GameObject �̎Q�Ɛ�
	void Draw(const std::shared_ptr<GameObject>& obj);
};

#endif
