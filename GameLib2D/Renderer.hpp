#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Component.hpp"
#include "Math.hpp"

// @brief ���ׂẴ����_���[�̂��߂̈�ʓI�ȋ@�\
class Renderer : public Component {
private:
	int order;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Renderer() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Renderer(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Renderer() noexcept = default;

	// @brief �`��
	virtual void Render() const {}

	// @brief "OnBecameInvisible" �͔C�ӂ̃J�����ŃI�u�W�F�N�g���\������Ȃ��Ȃ�Ƃ��ɌĂяo����܂��B
	virtual void OnBecameInvisible() {} // TODO: OnBecameInvisible ��X�ǉ�

	// @brief "OnBecameVisible" �͔C�ӂ̃J�����ŃI�u�W�F�N�g��������悤�ɂȂ����Ƃ��ɌĂяo����܂��B
	virtual void OnBecameVisible() {} // TODO: OnBecameVisible ��X�ǉ�

	// @brief �`�揇���Z�b�g(-5 �` 5)
	void SetOrder(int newOrder) {
		order = math::Clamp(newOrder, -5, 5);
	}

	// @brief �`�揇�l��Ԃ�
	NODISCARD int GetOrder() const {
		return order;
	}
};

#endif 
